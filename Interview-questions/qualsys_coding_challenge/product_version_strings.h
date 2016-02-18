#ifndef PRODUCT_VERSION_STRINGS_H_INCLUDED
#define PRODUCT_VERSION_STRINGS_H_INCLUDED

// files to include in resource file
#define COMPANY_NAME_STR "Simonton Chicken Farm"
#define FILE_DESCRIPTION_STR "Demo app with lined list class with insert function"
#define LEGAL_COPYRIGHT_STR "(c) 2016"
#define ORIGINAL_FILENAME_STR "Linked_list_with_insert.exe"
#define PRODUCT_NAME_STR "Linkedlist with insert"
#define AUTHOR_STR "Mark Simonton"
#define INTERNAL_NAME_STR "Linked_list_with_insert.exe"
// INTERNAL MSFT things
#define VS_VERSION_INFO 0x1L // version structure version info

// if the associated bit-flags are set populate this with some value
#define SPECIAL_BUILD_STR ""
#define PRIVATE_BUILD_STR ""

// bit-flags
#define VER_PRIVATEBUILD 0x0L
#define VER_PRERELEASE 0x0L
#define VOS_NT  0x00040000L
#define VOS__WINDOWS32 0x4L
#define VOS_NT_WINDOWS32 (VOS_NT | VOS__WINDOWS32)
// see https://msdn.microsoft.com/en-us/library/windows/desktop/ms646997%28v=vs.85%29.aspx
#define VFT_APP 0x1L
#define VFT_DLL 0x2L
#define VFT_DRV 0x00000003L
#define VFT_STATIC_LIB 0x00000007L


#define VFT2_UNKNOWN 0x0L
/*
VS_FF_DEBUG	File contains debugging information or is compiled with debugging features enabled.
VS_FF_PATCHED	File has been modified and is not identical to the original shipping file of the same version number.
VS_FF_PRERELEASE	File is a development version, not a commercially released product.
VS_FF_PRIVATEBUILD	File was not built using standard release procedures. If this value is given, the StringFileInfo block must contain a PrivateBuild string.
VS_FF_SPECIALBUILD	File was built by the original company using standard release procedures but is a variation of the standard file of the same version number. If this value is given, the StringFileInfo block block must contain a SpecialBuild string.
VS_FFI_FILEFLAGSMASK	A combination of all the preceding values.
 */
#define VS_FF_DEBUG 0x00000001L
#define VS_FF_PRERELEASE 0x00000002L
#define VS_FF_PATCHED 0x00000004L
#define VS_FF_PRIVATEBUILD 0x00000008L
#define VS_FF_INFOINFERRED 0x00000010L
#define VS_FF_SPECIALBUILD 0x00000020L

#define VS_FFI_FILEFLAGSMASK (VS_FF_DEBUG | VS_FF_PRERELEASE | VS_FF_PATCHED | VS_FF_PRIVATEBUILD | VS_FF_INFOINFERRED | VS_FF_SPECIALBUILD)

#endif // PRODUCT_VERSION_STRINGS_H_INCLUDED
