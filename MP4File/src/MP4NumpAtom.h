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


#ifndef MP4NumpAtom_h
	#define MP4NumpAtom_h

	#include "MP4Atom.h"
	#include "MP4FileErrors.h"


	typedef class MP4NumpAtom: public MP4Atom {

		private:
			MP4UInteger64BitsProperty_t				_mui64pPackets;

		protected:
			MP4NumpAtom (const MP4NumpAtom &);

			MP4NumpAtom &operator = (const MP4NumpAtom &);

			virtual Error prepareChildrensAtomsInfo (void);

			virtual Error createProperties (
				unsigned long *pulPropertiesSize);

			virtual Error readProperties (
				unsigned long *pulPropertiesSize);

			virtual Error writeProperties (int iFileDescriptor);

			virtual Error getPropertiesSize (
				unsigned long *pulPropertiesSize);

			virtual Error appendPropertiesDump (Buffer_p pbBuffer);

			virtual Error printPropertiesOnStdOutput (void);

		public:
			MP4NumpAtom ();

			virtual ~MP4NumpAtom ();

			#ifdef WIN32
				virtual Error init (MP4Atom *pmaParentAtom,
					FileReader_p pfFile,
					__int64 ullAtomStartOffset, __int64 ullAtomSize,
					unsigned long ulHeaderSize,
					PMutex_p pmtMP4File, long lAtomLevel, Boolean_t bUse64Bits,
					Boolean_t bUseMP4ConsistencyCheck,
					MP4Atom:: Standard_t sStandard, Tracer_p ptTracer);
			#else
				virtual Error init (MP4Atom *pmaParentAtom,
					FileReader_p pfFile,
					unsigned long long ullAtomStartOffset, unsigned long long ullAtomSize,
					unsigned long ulHeaderSize,
					PMutex_p pmtMP4File, long lAtomLevel, Boolean_t bUse64Bits,
					Boolean_t bUseMP4ConsistencyCheck,
					MP4Atom:: Standard_t sStandard, Tracer_p ptTracer);
			#endif

			virtual Error getType (char *pType);

			#ifdef WIN32
				Error getPackets (__int64 *pullPackets);
			#else
				Error getPackets (unsigned long long *pullPackets);
			#endif

			#ifdef WIN32
				Error setPackets (__int64 ullPackets);
			#else
				Error setPackets (unsigned long long ullPackets);
			#endif

			#ifdef WIN32
				Error incrementPackets (__int64 llIncrement);
			#else
				Error incrementPackets (long long llIncrement);
			#endif

	} MP4NumpAtom_t, *MP4NumpAtom_p;

#endif
