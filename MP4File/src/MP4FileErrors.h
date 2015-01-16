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


#ifndef MP4FileErrors_h
	#define MP4FileErrors_h

	#include "Error.h"
	#include <iostream>


	enum MP4FileErrorsCodes {

		// MP4Property
		MP4F_MP4PROPERTY_INIT_FAILED,
		MP4F_MP4PROPERTY_GETNAME_FAILED,
		MP4F_MP4PROPERTY_GETVALUE_FAILED,
		MP4F_MP4PROPERTY_SETVALUE_FAILED,
		MP4F_MP4PROPERTY_INCREMENTVALUE_FAILED,
		MP4F_MP4PROPERTY_GETTYPE_FAILED,
		MP4F_MP4PROPERTY_WRITE_FAILED,
		MP4F_MP4PROPERTY_PROPERTYTYPEWRONG,

		// MP4UInteger8BitsProperty
		MP4F_MP4UINTEGER8BITSPROPERTY_INIT_FAILED,
		MP4F_MP4UINTEGER8BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4UINTEGER8BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4UINTEGER8BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4UINTEGER8BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4UInteger16BitsProperty
		MP4F_MP4UINTEGER16BITSPROPERTY_INIT_FAILED,
		MP4F_MP4UINTEGER16BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4UINTEGER16BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4UINTEGER16BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4UINTEGER16BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4UInteger24BitsProperty
		MP4F_MP4UINTEGER24BITSPROPERTY_INIT_FAILED,
		MP4F_MP4UINTEGER24BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4UINTEGER24BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4UINTEGER24BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4UINTEGER24BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4UInteger32BitsProperty
		MP4F_MP4UINTEGER32BITSPROPERTY_INIT_FAILED,
		MP4F_MP4UINTEGER32BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4UINTEGER32BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4UINTEGER32BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4UINTEGER32BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4UInteger64BitsProperty
		MP4F_MP4UINTEGER64BITSPROPERTY_INIT_FAILED,
		MP4F_MP4UINTEGER64BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4UINTEGER64BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4UINTEGER64BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4UINTEGER64BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4Float16BitsProperty
		MP4F_MP4FLOAT16BITSPROPERTY_INIT_FAILED,
		MP4F_MP4FLOAT16BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4FLOAT16BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4FLOAT16BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4FLOAT16BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4Float32BitsProperty
		MP4F_MP4FLOAT32BITSPROPERTY_INIT_FAILED,
		MP4F_MP4FLOAT32BITSPROPERTY_GETSIZE_FAILED,
		MP4F_MP4FLOAT32BITSPROPERTY_WRITE_FAILED,
		MP4F_MP4FLOAT32BITSPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4FLOAT32BITSPROPERTY_APPENDDUMP_FAILED,

		// MP4StringNullTerminatedProperty
		MP4F_MP4STRINGNULLTERMINATEDPROPERTY_INIT_FAILED,
		MP4F_MP4STRINGNULLTERMINATEDPROPERTY_GETSIZE_FAILED,
		MP4F_MP4STRINGNULLTERMINATEDPROPERTY_WRITE_FAILED,
		MP4F_MP4STRINGNULLTERMINATEDPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4STRINGNULLTERMINATEDPROPERTY_APPENDDUMP_FAILED,

		// MP4StringLastProperty
		MP4F_MP4STRINGLASTPROPERTY_INIT_FAILED,
		MP4F_MP4STRINGLASTPROPERTY_GETSIZE_FAILED,
		MP4F_MP4STRINGLASTPROPERTY_WRITE_FAILED,
		MP4F_MP4STRINGLASTPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4STRINGLASTPROPERTY_APPENDDUMP_FAILED,

		// MP4StringFixedProperty
		MP4F_MP4STRINGFIXEDPROPERTY_INIT_FAILED,
		MP4F_MP4STRINGFIXEDPROPERTY_GETSIZE_FAILED,
		MP4F_MP4STRINGFIXEDPROPERTY_WRITE_FAILED,
		MP4F_MP4STRINGFIXEDPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4STRINGFIXEDPROPERTY_APPENDDUMP_FAILED,

		// MP4StringCountedProperty
		MP4F_MP4STRINGCOUNTEDPROPERTY_INIT_FAILED,
		MP4F_MP4STRINGCOUNTEDPROPERTY_GETSIZE_FAILED,
		MP4F_MP4STRINGCOUNTEDPROPERTY_WRITE_FAILED,
		MP4F_MP4STRINGCOUNTEDPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4STRINGCOUNTEDPROPERTY_APPENDDUMP_FAILED,
		MP4F_MP4STRINGCOUNTEDPROPERTY_CHARSNUMBERWRONG,

		// MP4BytesProperty
		MP4F_MP4BYTESPROPERTY_INIT_FAILED,
		MP4F_MP4BYTESPROPERTY_GETSIZE_FAILED,
		MP4F_MP4BYTESPROPERTY_WRITE_FAILED,
		MP4F_MP4BYTESPROPERTY_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4BYTESPROPERTY_APPENDDUMP_FAILED,
		MP4F_MP4BYTESPROPERTY_GETDATA_FAILED,
		MP4F_MP4BYTESPROPERTY_GETPOINTERTODATA_FAILED,

		// MP4Atom
		MP4F_MP4ATOM_INIT_FAILED,
		MP4F_MP4ATOM_FINISH_FAILED,
		MP4F_MP4ATOM_LOCKMP4FILE_FAILED,
		MP4F_MP4ATOM_UNLOCKMP4FILE_FAILED,
		MP4F_MP4ATOM_APPENDDUMP_FAILED,
		MP4F_MP4ATOM_APPENDPROPERTIESDUMP_FAILED,
		MP4F_MP4ATOM_PRINTONSTDOUTPUT_FAILED,
		MP4F_MP4ATOM_PRINTPROPERTIESONSTDOUTPUT_FAILED,
		MP4F_MP4ATOM_WRITE_FAILED,
		MP4F_MP4ATOM_SEARCHATOM_FAILED,
		MP4F_MP4ATOM_ADDCHILD_FAILED,
		MP4F_MP4ATOM_DELETECHILD_FAILED,
		MP4F_MP4ATOM_GETPARENT_FAILED,
		MP4F_MP4ATOM_GETCHILD_FAILED,
		MP4F_MP4ATOM_GETPROPERTIESSIZE_FAILED,
		MP4F_MP4ATOM_GETCHILDINDEX_FAILED,
		MP4F_MP4ATOM_GETCHILDRENNUMBER_FAILED,
		MP4F_MP4ATOM_GETSTARTOFFSET_FAILED,
		MP4F_MP4ATOM_INCREMENTSTARTOFFSET_FAILED,
		MP4F_MP4ATOM_CHANGESIZEMANAGEMENT_FAILED,
		MP4F_MP4ATOM_GETSIZE_FAILED,
		MP4F_MP4ATOM_GETSTANDARD_FAILED,
		MP4F_MP4ATOM_GETTYPE_FAILED,
		MP4F_MP4ATOM_PREPARECHILDRENATOMSINFO_FAILED,
		MP4F_MP4ATOM_CREATEPROPERTIES_FAILED,
		MP4F_MP4ATOM_READPROPERTIES_FAILED,
		MP4F_MP4ATOM_WRITEPROPERTIES_FAILED,
		MP4F_MP4ATOM_CREATECHILDATOMS_FAILED,
		MP4F_MP4ATOM_READCHILDATOMS_FAILED,
		MP4F_MP4ATOM_CONSISTENCYCHECK_FAILED,
		MP4F_MP4ATOM_BUILDATOM_FAILED,
		MP4F_MP4ATOM_BUILDDESCRIPTOR_FAILED,
		MP4F_MP4ATOM_ISDESCRIPTOR_FAILED,
		MP4F_MP4ATOM_GETDESCRIPTORTAG_FAILED,
		MP4F_MP4ATOM_ATOMTYPEUNKNOWN,
		MP4F_MP4ATOM_DESCRIPTORTYPEUNKNOWN,
		MP4F_MP4ATOM_DESCRIPTORTAGUNKNOWN,
		MP4F_MP4ATOM_TRACKTYPEUNKNOWN,
		MP4F_MP4ATOM_CODECUNKNOWN,
		MP4F_MP4ATOM_PROPERTYNOTFOUND,
		MP4F_MP4ATOM_ATOMNOTFOUND,
		MP4F_MP4ATOM_WRONGATOMPARENT,
		MP4F_MP4ATOM_ATOMINSTANCESNOTCORRECTED,
		MP4F_MP4ATOM_ATOMNOTINCORRECTPOSITION,
		MP4F_MP4ATOM_ATOMMANDATORYNOTEXIST,

		// MP4CprtAtom
		MP4F_MP4CPRTATOM_SETNOTICE_FAILED,

		// MP4D263Atom
		MP4F_MP4D263ATOM_GETH263LEVEL_FAILED,
		MP4F_MP4D263ATOM_SETH263LEVEL_FAILED,
		MP4F_MP4D263ATOM_GETH263PROFILE_FAILED,
		MP4F_MP4D263ATOM_SETH263PROFILE_FAILED,

		// MP4FtypAtom
		MP4F_MP4FTYPATOM_GETMAJORBRAND_FAILED,
		MP4F_MP4FTYPATOM_SETMAJORBRAND_FAILED,
		MP4F_MP4FTYPATOM_GETMINORVERSION_FAILED,
		MP4F_MP4FTYPATOM_SETMINORVERSION_FAILED,
		MP4F_MP4FTYPATOM_GETCOMPATIBLEBRANDSCOUNT_FAILED,
		MP4F_MP4FTYPATOM_SETCOMPATIBLEBRANDSCOUNT_FAILED,
		MP4F_MP4FTYPATOM_GETBRAND_FAILED,
		MP4F_MP4FTYPATOM_SETBRAND_FAILED,

		// MP4HdlrAtom
		MP4F_MP4HDLRATOM_GETHANDLERTYPE_FAILED,

		// MP4HintAtom
		MP4F_MP4HINTATOM_GETENTRIESNUMBER_FAILED,
		MP4F_MP4HINTATOM_GETTRACKSREFERENCESTABLE_FAILED,

		// MP4MdatAtom
		MP4F_MP4MDATATOM_GETPOINTERTODATA_FAILED,
		MP4F_MP4MDATATOM_GETDATASTARTOFFSET_FAILED,
		MP4F_MP4MDATATOM_APPENDDATA_FAILED,
		MP4F_MP4MDATATOM_BYTESTOREADTOOBIG,

		// MP4MdhdAtom
		MP4F_MP4MDHDATOM_GETTIMESCALE_FAILED,
		MP4F_MP4MDHDATOM_GETDURATION_FAILED,

		// MP4Mp4vAtom
		MP4F_MP4MP4VATOM_GETWIDTH_FAILED,
		MP4F_MP4MP4VATOM_SETWIDTH_FAILED,
		MP4F_MP4MP4VATOM_GETHEIGHT_FAILED,
		MP4F_MP4MP4VATOM_SETHEIGHT_FAILED,

		// MP4MvhdAtom
		MP4F_MP4MVHDATOM_GETTIMESCALE_FAILED,
		MP4F_MP4MVHDATOM_GETDURATION_FAILED,

		// MP4NumpAtom
		MP4F_MP4NUMPATOM_GETPACKETS_FAILED,

		// MP4RootAtom
		MP4F_MP4ROOTATOM_MOVEMOOVATOMASLASTATOM_FAILED,
		MP4F_MP4ROOTATOM_MOOVATOMNOTFOUND,

		// MP4RtpAtom
		MP4F_MP4RTPATOM_GETMAXPACKETSIZE_FAILED,

		// MP4S263Atom
		MP4F_MP4S263ATOM_GETWIDTH_FAILED,
		MP4F_MP4S263ATOM_SETWIDTH_FAILED,
		MP4F_MP4S263ATOM_GETHEIGHT_FAILED,
		MP4F_MP4S263ATOM_SETHEIGHT_FAILED,

		// MP4SdpAtom
		MP4F_MP4SDPATOM_GETSDPTEXT_FAILED,

		// MP4StcoAtom
		MP4F_MP4STCOATOM_GETCHUNKOFFSETTABLE_FAILED,

		// MP4StscAtom
		MP4F_MP4STSCATOM_GETSAMPLETOCHUNKTABLE_FAILED,

		// MP4StszAtom
		MP4F_MP4STSZATOM_GETSAMPLESNUMBER_FAILED,

		// MP4TkhdAtom
		MP4F_MP4TKHDATOM_GETTRACKID_FAILED,

		// MP4TimsAtom
		MP4F_MP4TIMSATOM_GETTIMESCALE_FAILED,

		// MP4UuidAtom
		MP4F_MP4UUIDATOM_GETEXTENDEDTYPE_FAILED,
		MP4F_MP4UUIDATOM_SETEXTENDEDTYPE_FAILED,
		MP4F_MP4UUIDATOM_SETDATA_FAILED,

		// MP4DecoderConfigDescr
		MP4F_MP4DECODERCONFIGDESCR_GETAVGBITRATE_FAILED,

		// MP4Descr
		MP4F_MP4DESCR_GETTAG_FAILED,

		// MP4ESDescr
		MP4F_MP4ESDESCR_GETOCRSTREAMFLAG_FAILED,

		// MP4InitialObjectDescr
		MP4F_MP4INITIALOBJECTDESCR_GETVISUALPROFILELEVELINDICATION_FAILED,
		MP4F_MP4INITIALOBJECTDESCR_SETVISUALPROFILELEVELINDICATION_FAILED,

		// MP4SyncLayerConfigDescr
		MP4F_MP4SYNCLAYERCONFIGDESCR_WRONGTIMESTAMPLENGTH,

		// MP4File
		MP4F_MP4FILE_INIT_FAILED,
		MP4F_MP4FILE_FINISH_FAILED,
		MP4F_MP4FILE_GETFILE_FAILED,
		MP4F_MP4FILE_GETDUMP_FAILED,
		MP4F_MP4FILE_INITIALIZETRACKSVECTOR_FAILED,
		MP4F_MP4FILE_GETTRACKSINFO_FAILED,
		MP4F_MP4FILE_GETFREEPAYLOADSNUMBER_FAILED,
		MP4F_MP4FILE_GETHINTTRAKFROMMEDIATRAKIDENTIFIER_FAILED,
		MP4F_MP4FILE_GETHINTTRACKINFOFROMMEDIATRACKINFO_FAILED,
		MP4F_MP4FILE_GETMP4FILESTATUS_FAILED,
		MP4F_MP4FILE_GETMP4FILEPATH_FAILED,
		MP4F_MP4FILE_GETROOTATOM_FAILED,
		MP4F_MP4FILE_WRITE_FAILED,
		MP4F_MP4FILE_SEARCHATOM_FAILED,
		MP4F_MP4FILE_GETMOVIEDURATION_FAILED,
		MP4F_MP4FILE_GETTRAKINFOFROMIDENTIFIER_FAILED,
		MP4F_MP4FILE_GETTRAKINFOFROMTRACKPOINTER_FAILED,
		MP4F_MP4FILE_GETSAMPLESNUMBER_FAILED,
		MP4F_MP4FILE_GETPREVIOUSSYNCSAMPLE_FAILED,
		MP4F_MP4FILE_SDPTEXTWRONG,
		MP4F_MP4FILE_NULLMAXMEDIASAMPLESIZE,
		MP4F_MP4FILE_NULLTIMESCALE,
		MP4F_MP4FILE_NOESCONFIGURATIONFOUND,
		MP4F_MP4FILE_WRONGESCONFIGURATIONFOUND,
		MP4F_MP4FILE_ESCONFIGTOOLARGEFORRTPPAYLOAD,
		MP4F_MP4FILE_HINTTRACKNOTFOUND,
		MP4F_MP4FILE_VIDEOHINTTRACKNOTFOUND,
		MP4F_MP4FILE_VIDEOTRACKNOTFOUND,
		MP4F_MP4FILE_AUDIOHINTTRACKNOTFOUND,
		MP4F_MP4FILE_TRACKNOTRECONIZED_FAILED,
		MP4F_MP4FILE_REQUESTEDSTOPTIMEREACHED,

		// MP4FileFactory
		MP4F_MP4FILEFACTORY_INIT_FAILED,
		MP4F_MP4FILEFACTORY_FINISH_FAILED,
		MP4F_MP4FILEFACTORY_GETMP4FILE_FAILED,
		MP4F_MP4FILEFACTORY_ISMP4FILEINCACHE_FAILED,
		MP4F_MP4FILEFACTORY_RELEASEMP4FILE_FAILED,
		MP4F_MP4FILEFACTORY_MP4FILENOTFOUND,
		MP4F_MP4FILEFACTORY_RELEASEOFAFILENOREQUIRED,
		MP4F_MP4FILEFACTORY_REMOVEOLDERNOTUSEDMP4FILE_FAILED,
		MP4F_MP4FILEFACTORY_FINDINDEXWHEREINSERT_FAILED,
		MP4F_MP4FILEFACTORY_FILENOTFOUND,

		// MP4Utility
		MP4F_MP4UTILITY_READFROMMDATATOM_FAILED,
		MP4F_MP4UTILITY_GETCHUNKOFFSETFROMCHUNKNUMBER_FAILED,
		MP4F_MP4UTILITY_GETCHUNKFIRSTLASTSAMPLE_FAILED,
		MP4F_MP4UTILITY_GETPOINTERFROMMDATATOM_FAILED,
		MP4F_MP4UTILITY_GETSAMPLESIZE_FAILED,
		MP4F_MP4UTILITY_GETNEWTRACKIDENTIFIER_FAILED,
		MP4F_MP4UTILITY_NOPAYLOADAVAILABLE,
		MP4F_MP4UTILITY_UPDATESAMPLESIZES_FAILED,
		MP4F_MP4UTILITY_UPDATESAMPLETIMES_FAILED,
		MP4F_MP4UTILITY_UPDATERENDERINGOFFSETS_FAILED,
		MP4F_MP4UTILITY_UPDATESYNCSAMPLES_FAILED,
		MP4F_MP4UTILITY_UPDATESAMPLETOCHUNK_FAILED,
		MP4F_MP4UTILITY_UPDATECHUNKOFFSET_FAILED,
		MP4F_MP4UTILITY_UPDATEDURATIONS_FAILED,
		MP4F_MP4UTILITY_UPDATEMODIFICATIONSTIMES_FAILED,
		MP4F_MP4UTILITY_GETRENDERINGOFFSETFROMSAMPLENUMBER_FAILED,
		MP4F_MP4UTILITY_ISSYNCSAMPLE_FAILED,
		MP4F_MP4UTILITY_GETPOINTERTRACKESCONFIGURATION_FAILED,
		MP4F_MP4UTILITY_GETMAXSAMPLESIZE_FAILED,
		MP4F_MP4UTILITY_GETPOINTERTOSAMPLE_FAILED,
		MP4F_MP4UTILITY_GETCODECNAME_FAILED,
		MP4F_MP4UTILITY_WRONGHANDLERTYPE,

		// MP4TrackInfo
		MP4F_MP4TRACKINFO_INIT_FAILED,
		MP4F_MP4TRACKINFO_FINISH_FAILED,
		MP4F_MP4TRACKINFO_GETTRACKNAME_FAILED,
		MP4F_MP4TRACKINFO_GETHANDLERTYPE_FAILED,
		MP4F_MP4TRACKINFO_GETCTTSATOM_FAILED,
		MP4F_MP4TRACKINFO_GETAACAUDIODECODERCONFIGDESCR_FAILED,
		MP4F_MP4TRACKINFO_GETMPEG4VIDEODECODERCONFIGDESCR_FAILED,
		MP4F_MP4TRACKINFO_GETD263ATOM_FAILED,
		MP4F_MP4TRACKINFO_GETDIMMATOM_FAILED,
		MP4F_MP4TRACKINFO_GETDINFATOM_FAILED,
		MP4F_MP4TRACKINFO_GETDMAXATOM_FAILED,
		MP4F_MP4TRACKINFO_GETDMEDATOM_FAILED,
		MP4F_MP4TRACKINFO_GETDREFATOM_FAILED,
		MP4F_MP4TRACKINFO_GETELSTATOM_FAILED,
		MP4F_MP4TRACKINFO_GETHDLRATOM_FAILED,
		MP4F_MP4TRACKINFO_GETHINFATOM_FAILED,
		MP4F_MP4TRACKINFO_GETHINTATOM_FAILED,
		MP4F_MP4TRACKINFO_GETHMHDATOM_FAILED,
		MP4F_MP4TRACKINFO_GETMAXRATOM_FAILED,
		MP4F_MP4TRACKINFO_GETMDHDATOM_FAILED,
		MP4F_MP4TRACKINFO_GETMINFATOM_FAILED,
		MP4F_MP4TRACKINFO_GETMP4VATOM_FAILED,
		MP4F_MP4TRACKINFO_GETNUMPATOM_FAILED,
		MP4F_MP4TRACKINFO_GETPAYTATOM_FAILED,
		MP4F_MP4TRACKINFO_GETPMAXATOM_FAILED,
		MP4F_MP4TRACKINFO_GETRTPATOM_FAILED,
		MP4F_MP4TRACKINFO_GETS263ATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSAMRATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSAWBATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSDPATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSNROATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTBLATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTCOATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTSCATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTSDATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTSSATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTSZATOM_FAILED,
		MP4F_MP4TRACKINFO_GETSTTSATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTIMSATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTKHDATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTPYLATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTRAKATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTRPYATOM_FAILED,
		MP4F_MP4TRACKINFO_GETTSROATOM_FAILED,
		MP4F_MP4TRACKINFO_GETMDHDTIMESCALE_FAILED,
		MP4F_MP4TRACKINFO_GETTIMSTIMESCALE_FAILED,
		MP4F_MP4TRACKINFO_GETDURATION_FAILED,
		MP4F_MP4TRACKINFO_GETSAMPLESNUMBER_FAILED,
		MP4F_MP4TRACKINFO_GETMAXSAMPLESIZE_FAILED,
		MP4F_MP4TRACKINFO_GETAVGBITRATE_FAILED,
		MP4F_MP4TRACKINFO_GETCODEC_FAILED,
		MP4F_MP4TRACKINFO_GETPOINTERTRACKESCONFIGURATION_FAILED,
		MP4F_MP4TRACKINFO_GETTRACKIDENTIFIER_FAILED,
		MP4F_MP4TRACKINFO_GETOBJECTTYPEINDICATION_FAILED,
		MP4F_MP4TRACKINFO_ADDHINTTRACK_FAILED,
		MP4F_MP4TRACKINFO_DELETEHINTTRACK_FAILED,
		MP4F_MP4TRACKINFO_CODECNOTINITIALIZED,
		MP4F_MP4TRACKINFO_OBJECTTYPEINDICATIONNOTINITIALIZED,
		MP4F_MP4TRACKINFO_NOESCONFIGURATIONFOUND,
		MP4F_MP4TRACKINFO_APPLIEDHINTTRACK,

		// common
		MP4F_NEW_FAILED,
		MP4F_GETTIMEOFDAY_FAILED,
		MP4F_ACTIVATION_WRONG,
		MP4F_NOTCONSISTENT,
		MP4F_OPERATIONNOTALLOWED,
		MP4F_HASHMAP_ERROR,
		MP4F_NOTTESTED,
		MP4F_NOTIMPLEMENTEDYET,

		// Insert here other errors...

		MP4F_MAXERRORS
	} ;

	#ifdef WIN32
		// warning C4267: 'argument' : conversion from 'size_t' to 'long', possible loss of data

		#pragma warning (disable : 4267)
	#endif

	// declaration of class error
	dclCustomErrorClass (MP4FileErrors, MP4F_MAXERRORS)


#endif