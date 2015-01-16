/*
 Copyright (C) Giuliano Catrambone (giuliano.catrambone@catrasoftware.it)

 This program is free software; you can redistribute it and/or 
 modify it under the terms of the GNU General Public License 
 as published by the Free Software Foundation; either 
 version 2 of the License, or (at your option) any later 
 version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 Commercial use other than under the terms of the GNU General Public
 License is allowed only after express negotiation of conditions
 with the authors.
*/


#include "MP4DmaxAtom.h"
#include "FileIO.h"
#ifdef WIN32
	#include <stdio.h>
#else
	#include <unistd.h>
#endif
#include <assert.h>



MP4DmaxAtom:: MP4DmaxAtom (void): MP4Atom ()

{

}


MP4DmaxAtom:: ~MP4DmaxAtom (void)

{

}



MP4DmaxAtom:: MP4DmaxAtom (const MP4DmaxAtom &)

{

	assert (1==0);

	// to do

}


MP4DmaxAtom &MP4DmaxAtom:: operator = (const MP4DmaxAtom &)

{

	assert (1==0);

	// to do

	return *this;

}


#ifdef WIN32
	Error MP4DmaxAtom:: init (MP4Atom_p pmaParentAtom,
		FileReader_p pfFile,
		__int64 ullAtomStartOffset, __int64 ullAtomSize,
		unsigned long ulHeaderSize,
		PMutex_p pmtMP4File, long lAtomLevel, Boolean_t bUse64Bits,
		Boolean_t bUseMP4ConsistencyCheck,
		MP4Atom:: Standard_t sStandard, Tracer_p ptTracer)
#else
	Error MP4DmaxAtom:: init (MP4Atom_p pmaParentAtom,
		FileReader_p pfFile,
		unsigned long long ullAtomStartOffset, unsigned long long ullAtomSize,
		unsigned long ulHeaderSize,
		PMutex_p pmtMP4File, long lAtomLevel, Boolean_t bUse64Bits,
		Boolean_t bUseMP4ConsistencyCheck,
		MP4Atom:: Standard_t sStandard, Tracer_p ptTracer)
#endif

{

	return MP4Atom:: init (pmaParentAtom, pfFile,
		ullAtomStartOffset, ullAtomSize, ulHeaderSize,
		pmtMP4File, lAtomLevel, bUse64Bits, bUseMP4ConsistencyCheck,
		sStandard, ptTracer);
}


Error MP4DmaxAtom:: prepareChildrensAtomsInfo (void)

{

	return errNoError;
}


Error MP4DmaxAtom:: createProperties (
	unsigned long *pulPropertiesSize)

{

	unsigned long			ulValue;
	Boolean_t				bIsImplicitProperty;


	ulValue							= 0;
	bIsImplicitProperty				= false;

	// 0: max packet duration
	if (_mui32pMilliSecs. init ("MilliSecs", 1, &bIsImplicitProperty,
		&ulValue, _ptTracer) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_INIT_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}

	if (getPropertiesSize (pulPropertiesSize) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4ATOM_GETPROPERTIESSIZE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: readProperties (
	unsigned long *pulPropertiesSize)

{
	#ifdef WIN32
		__int64						llCurrentFilePosition;
	#else
		long long					llCurrentFilePosition;
	#endif


	if (_pfFile -> seek (_ullAtomStartOffset + _ulHeaderSize,
		SEEK_SET, &llCurrentFilePosition) != errNoError)
	{
		Error err = ToolsErrors (__FILE__, __LINE__,
			TOOLS_FILEREADER_SEEK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR,
			(const char *) err, __FILE__, __LINE__);

		return err;
	}

	// 0: max packet duration
	if (_mui32pMilliSecs. init ("MilliSecs", 1, _pfFile,
		_ptTracer) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_INIT_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}

	if (getPropertiesSize (pulPropertiesSize) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4ATOM_GETPROPERTIESSIZE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: writeProperties (int iFileDescriptor)

{

	#ifdef WIN32
		__int64						ullAtomPropertiesStartOffset;
		__int64						llCurrentPosition;
	#else
		unsigned long long			ullAtomPropertiesStartOffset;
		long long					llCurrentPosition;
	#endif


	ullAtomPropertiesStartOffset			= _ullAtomStartOffset + _ulHeaderSize;

	if (FileIO:: seek (iFileDescriptor, ullAtomPropertiesStartOffset,
		SEEK_SET, &llCurrentPosition) != errNoError)
	{
		Error err = ToolsErrors (__FILE__, __LINE__,
			TOOLS_FILEIO_SEEK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}

	if (_mui32pMilliSecs. write (iFileDescriptor) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_WRITE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: getPropertiesSize (unsigned long *pulPropertiesSize)

{

	unsigned long				ulSize;


	*pulPropertiesSize					= 0;

	if (_mui32pMilliSecs. getSize (&ulSize) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_GETSIZE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}
	*pulPropertiesSize					+= ulSize;


	return errNoError;
}


Error MP4DmaxAtom:: getType (char *pType)

{
	strcpy (pType, "dmax");


	return errNoError;
}


Error MP4DmaxAtom:: appendPropertiesDump (Buffer_p pbBuffer)

{

	long						lLevelIndex;


	for (lLevelIndex = 0; lLevelIndex < _lAtomLevel + 1; lLevelIndex++)
	{
		if (pbBuffer -> append ("  ") != errNoError)
		{
			Error err = ToolsErrors (__FILE__, __LINE__,
				TOOLS_BUFFER_APPEND_FAILED);
			_ptTracer -> trace (Tracer:: TRACER_LERRR,
				(const char *) err, __FILE__, __LINE__);

			return err;
		}
	}

	if (_mui32pMilliSecs. appendDump (pbBuffer) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_APPENDDUMP_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: printPropertiesOnStdOutput (void)

{

	long						lLevelIndex;


	for (lLevelIndex = 0; lLevelIndex < _lAtomLevel + 1; lLevelIndex++)
		std:: cout << "  ";

	if (_mui32pMilliSecs. printOnStdOutput () != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4UINTEGER32BITSPROPERTY_PRINTONSTDOUTPUT_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: getMilliSecs (unsigned long *pulMilliSecs)

{

	if (_pmtMP4File -> lock () != errNoError)
	{
		Error err = PThreadErrors (__FILE__, __LINE__,
			THREADLIB_PMUTEX_LOCK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR,
			(const char *) err, __FILE__, __LINE__);

		return err;
	}

	if (_mui32pMilliSecs. getValue (pulMilliSecs, 0) != errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4PROPERTY_GETVALUE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		if (_pmtMP4File -> unLock () != errNoError)
		{
			Error err = PThreadErrors (__FILE__, __LINE__,
				THREADLIB_PMUTEX_UNLOCK_FAILED);
			_ptTracer -> trace (Tracer:: TRACER_LERRR,
				(const char *) err, __FILE__, __LINE__);
		}

		return err;
	}

	if (_pmtMP4File -> unLock () != errNoError)
	{
		Error err = PThreadErrors (__FILE__, __LINE__,
			THREADLIB_PMUTEX_UNLOCK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR,
			(const char *) err, __FILE__, __LINE__);

		return err;
	}


	return errNoError;
}


Error MP4DmaxAtom:: setMilliSecs (unsigned long ulMilliSecs)

{

	unsigned long					ulSizeChangedInBytes;


	if (_pmtMP4File -> lock () != errNoError)
	{
		Error err = PThreadErrors (__FILE__, __LINE__,
			THREADLIB_PMUTEX_LOCK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR,
			(const char *) err, __FILE__, __LINE__);

		return err;
	}

	if (_mui32pMilliSecs. setValue (ulMilliSecs, 0, &ulSizeChangedInBytes) !=
		errNoError)
	{
		Error err = MP4FileErrors (__FILE__, __LINE__,
			MP4F_MP4PROPERTY_SETVALUE_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
			__FILE__, __LINE__);

		if (_pmtMP4File -> unLock () != errNoError)
		{
			Error err = PThreadErrors (__FILE__, __LINE__,
				THREADLIB_PMUTEX_UNLOCK_FAILED);
			_ptTracer -> trace (Tracer:: TRACER_LERRR,
				(const char *) err, __FILE__, __LINE__);
		}

		return err;
	}

	if (ulSizeChangedInBytes > 0)
	{
		if (changeSizeManagement (ulSizeChangedInBytes) != errNoError)
		{
			Error err = MP4FileErrors (__FILE__, __LINE__,
				MP4F_MP4ATOM_CHANGESIZEMANAGEMENT_FAILED);
			_ptTracer -> trace (Tracer:: TRACER_LERRR, (const char *) err,
				__FILE__, __LINE__);

			if (_pmtMP4File -> unLock () != errNoError)
			{
				Error err = PThreadErrors (__FILE__, __LINE__,
					THREADLIB_PMUTEX_UNLOCK_FAILED);
				_ptTracer -> trace (Tracer:: TRACER_LERRR,
					(const char *) err, __FILE__, __LINE__);
			}

			return err;
		}
	}

	if (_pmtMP4File -> unLock () != errNoError)
	{
		Error err = PThreadErrors (__FILE__, __LINE__,
			THREADLIB_PMUTEX_UNLOCK_FAILED);
		_ptTracer -> trace (Tracer:: TRACER_LERRR,
			(const char *) err, __FILE__, __LINE__);

		return err;
	}


	return errNoError;
}

