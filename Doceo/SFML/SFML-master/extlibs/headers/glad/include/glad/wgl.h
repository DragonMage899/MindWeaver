/**
 * Loader generated by glad 2.0.0-beta on Wed Jul 17 02:23:29 2019
 *
 * Generator: C/C++
 * Specification: wgl
 * Extensions: 10
 *
 * APIs:
 *  - wgl=1.0
 *
 * Options:
 *  - MX_GLOBAL = False
 *  - ON_DEMAND = False
 *  - LOADER = True
 *  - ALIAS = True
 *  - HEADER_ONLY = True
 *  - DEBUG = False
 *  - MX = False
 *
 * Commandline:
 *    --api='wgl=1.0' --extensions='WGL_ARB_create_context,WGL_ARB_create_context_profile,WGL_ARB_extensions_string,WGL_ARB_framebuffer_sRGB,WGL_ARB_multisample,WGL_ARB_pbuffer,WGL_ARB_pixel_format,WGL_EXT_extensions_string,WGL_EXT_framebuffer_sRGB,WGL_EXT_swap_control' c --loader --alias --header-only
 *
 * Online:
 *    http://glad.sh/#api=wgl%3D1.0&extensions=WGL_ARB_create_context%2CWGL_ARB_create_context_profile%2CWGL_ARB_extensions_string%2CWGL_ARB_framebuffer_sRGB%2CWGL_ARB_multisample%2CWGL_ARB_pbuffer%2CWGL_ARB_pixel_format%2CWGL_EXT_extensions_string%2CWGL_EXT_framebuffer_sRGB%2CWGL_EXT_swap_control&generator=c&options=LOADER%2CALIAS%2CHEADER_ONLY
 *
 */

#ifndef SF_GLAD_WGL_H_
#define SF_GLAD_WGL_H_

#include <windows.h>
#include <glad/gl.h>

#define SF_GLAD_WGL
#define GLAD_OPTION_WGL_LOADER
#define GLAD_OPTION_WGL_ALIAS
#define GLAD_OPTION_WGL_HEADER_ONLY

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLAD_PLATFORM_H_
#define GLAD_PLATFORM_H_

#ifndef GLAD_PLATFORM_WIN32
  #if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
    #define GLAD_PLATFORM_WIN32 1
  #else
    #define GLAD_PLATFORM_WIN32 0
  #endif
#endif

#ifndef GLAD_PLATFORM_APPLE
  #ifdef __APPLE__
    #define GLAD_PLATFORM_APPLE 1
  #else
    #define GLAD_PLATFORM_APPLE 0
  #endif
#endif

#ifndef GLAD_PLATFORM_EMSCRIPTEN
  #ifdef __EMSCRIPTEN__
    #define GLAD_PLATFORM_EMSCRIPTEN 1
  #else
    #define GLAD_PLATFORM_EMSCRIPTEN 0
  #endif
#endif

#ifndef GLAD_PLATFORM_UWP
  #if defined(_MSC_VER) && !defined(GLAD_INTERNAL_HAVE_WINAPIFAMILY)
    #ifdef __has_include
      #if __has_include(<winapifamily.h>)
        #define GLAD_INTERNAL_HAVE_WINAPIFAMILY 1
      #endif
    #elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
      #define GLAD_INTERNAL_HAVE_WINAPIFAMILY 1
    #endif
  #endif

  #ifdef GLAD_INTERNAL_HAVE_WINAPIFAMILY
    #include <winapifamily.h>
    #if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      #define GLAD_PLATFORM_UWP 1
    #endif
  #endif

  #ifndef GLAD_PLATFORM_UWP
    #define GLAD_PLATFORM_UWP 0
  #endif
#endif

#ifdef __GNUC__
  #define GLAD_GNUC_EXTENSION __extension__
#else
  #define GLAD_GNUC_EXTENSION
#endif

#ifndef GLAD_API_CALL
  #if defined(GLAD_API_CALL_EXPORT)
    #if GLAD_PLATFORM_WIN32 || defined(__CYGWIN__)
      #if defined(GLAD_API_CALL_EXPORT_BUILD)
        #if defined(__GNUC__)
          #define GLAD_API_CALL __attribute__ ((dllexport)) extern
        #else
          #define GLAD_API_CALL __declspec(dllexport) extern
        #endif
      #else
        #if defined(__GNUC__)
          #define GLAD_API_CALL __attribute__ ((dllimport)) extern
        #else
          #define GLAD_API_CALL __declspec(dllimport) extern
        #endif
      #endif
    #elif defined(__GNUC__) && defined(GLAD_API_CALL_EXPORT_BUILD)
      #define GLAD_API_CALL __attribute__ ((visibility ("default"))) extern
    #else
      #define GLAD_API_CALL extern
    #endif
  #else
    #define GLAD_API_CALL extern
  #endif
#endif

#ifdef APIENTRY
  #define GLAD_API_PTR APIENTRY
#elif GLAD_PLATFORM_WIN32
  #define GLAD_API_PTR __stdcall
#else
  #define GLAD_API_PTR
#endif

#ifndef GLAPI
#define GLAPI GLAD_API_CALL
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY GLAD_API_PTR
#endif

#define GLAD_MAKE_VERSION(major, minor) (major * 10000 + minor)
#define GLAD_VERSION_MAJOR(version) (version / 10000)
#define GLAD_VERSION_MINOR(version) (version % 10000)

#define GLAD_GENERATOR_VERSION "2.0.0-beta"

typedef void (*GLADapiproc)(void);

typedef GLADapiproc (*GLADloadfunc)(const char *name);
typedef GLADapiproc (*GLADuserptrloadfunc)(void *userptr, const char *name);

typedef void (*GLADprecallback)(const char *name, GLADapiproc apiproc, int len_args, ...);
typedef void (*GLADpostcallback)(void *ret, const char *name, GLADapiproc apiproc, int len_args, ...);

#endif /* GLAD_PLATFORM_H_ */

#define ERROR_INVALID_PROFILE_ARB 0x2096
#define ERROR_INVALID_VERSION_ARB 0x2095
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_ACCUM_ALPHA_BITS_ARB 0x2021
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_ACCUM_BLUE_BITS_ARB 0x2020
#define WGL_ACCUM_GREEN_BITS_ARB 0x201F
#define WGL_ACCUM_RED_BITS_ARB 0x201E
#define WGL_ALPHA_BITS_ARB 0x201B
#define WGL_ALPHA_SHIFT_ARB 0x201C
#define WGL_AUX_BUFFERS_ARB 0x2024
#define WGL_BLUE_BITS_ARB 0x2019
#define WGL_BLUE_SHIFT_ARB 0x201A
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_DEBUG_BIT_ARB 0x00000001
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_DRAW_TO_BITMAP_ARB 0x2002
#define WGL_DRAW_TO_PBUFFER_ARB 0x202D
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_FONT_LINES 0
#define WGL_FONT_POLYGONS 1
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20A9
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20A9
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_GENERIC_ACCELERATION_ARB 0x2026
#define WGL_GREEN_BITS_ARB 0x2017
#define WGL_GREEN_SHIFT_ARB 0x2018
#define WGL_MAX_PBUFFER_HEIGHT_ARB 0x2030
#define WGL_MAX_PBUFFER_PIXELS_ARB 0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB 0x202F
#define WGL_NEED_PALETTE_ARB 0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB 0x2005
#define WGL_NO_ACCELERATION_ARB 0x2025
#define WGL_NUMBER_OVERLAYS_ARB 0x2008
#define WGL_NUMBER_PIXEL_FORMATS_ARB 0x2000
#define WGL_NUMBER_UNDERLAYS_ARB 0x2009
#define WGL_PBUFFER_HEIGHT_ARB 0x2035
#define WGL_PBUFFER_LARGEST_ARB 0x2033
#define WGL_PBUFFER_LOST_ARB 0x2036
#define WGL_PBUFFER_WIDTH_ARB 0x2034
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_RED_BITS_ARB 0x2015
#define WGL_RED_SHIFT_ARB 0x2016
#define WGL_SAMPLES_ARB 0x2042
#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SHARE_ACCUM_ARB 0x200E
#define WGL_SHARE_DEPTH_ARB 0x200C
#define WGL_SHARE_STENCIL_ARB 0x200D
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_STEREO_ARB 0x2012
#define WGL_SUPPORT_GDI_ARB 0x200F
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_SWAP_COPY_ARB 0x2029
#define WGL_SWAP_EXCHANGE_ARB 0x2028
#define WGL_SWAP_LAYER_BUFFERS_ARB 0x2006
#define WGL_SWAP_MAIN_PLANE 0x00000001
#define WGL_SWAP_METHOD_ARB 0x2007
#define WGL_SWAP_OVERLAY1 0x00000002
#define WGL_SWAP_OVERLAY10 0x00000400
#define WGL_SWAP_OVERLAY11 0x00000800
#define WGL_SWAP_OVERLAY12 0x00001000
#define WGL_SWAP_OVERLAY13 0x00002000
#define WGL_SWAP_OVERLAY14 0x00004000
#define WGL_SWAP_OVERLAY15 0x00008000
#define WGL_SWAP_OVERLAY2 0x00000004
#define WGL_SWAP_OVERLAY3 0x00000008
#define WGL_SWAP_OVERLAY4 0x00000010
#define WGL_SWAP_OVERLAY5 0x00000020
#define WGL_SWAP_OVERLAY6 0x00000040
#define WGL_SWAP_OVERLAY7 0x00000080
#define WGL_SWAP_OVERLAY8 0x00000100
#define WGL_SWAP_OVERLAY9 0x00000200
#define WGL_SWAP_UNDEFINED_ARB 0x202A
#define WGL_SWAP_UNDERLAY1 0x00010000
#define WGL_SWAP_UNDERLAY10 0x02000000
#define WGL_SWAP_UNDERLAY11 0x04000000
#define WGL_SWAP_UNDERLAY12 0x08000000
#define WGL_SWAP_UNDERLAY13 0x10000000
#define WGL_SWAP_UNDERLAY14 0x20000000
#define WGL_SWAP_UNDERLAY15 0x40000000
#define WGL_SWAP_UNDERLAY2 0x00020000
#define WGL_SWAP_UNDERLAY3 0x00040000
#define WGL_SWAP_UNDERLAY4 0x00080000
#define WGL_SWAP_UNDERLAY5 0x00100000
#define WGL_SWAP_UNDERLAY6 0x00200000
#define WGL_SWAP_UNDERLAY7 0x00400000
#define WGL_SWAP_UNDERLAY8 0x00800000
#define WGL_SWAP_UNDERLAY9 0x01000000
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_ARB 0x200A
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TYPE_COLORINDEX_ARB 0x202C
#define WGL_TYPE_RGBA_ARB 0x202B
































struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
};
DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
typedef struct _GPU_DEVICE GPU_DEVICE;
typedef struct _GPU_DEVICE *PGPU_DEVICE;


#define WGL_VERSION_1_0 1
GLAD_API_CALL int SF_GLAD_WGL_VERSION_1_0;
#define WGL_ARB_create_context 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_create_context;
#define WGL_ARB_create_context_profile 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_create_context_profile;
#define WGL_ARB_extensions_string 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_extensions_string;
#define WGL_ARB_framebuffer_sRGB 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_framebuffer_sRGB;
#define WGL_ARB_multisample 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_multisample;
#define WGL_ARB_pbuffer 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_pbuffer;
#define WGL_ARB_pixel_format 1
GLAD_API_CALL int SF_GLAD_WGL_ARB_pixel_format;
#define WGL_EXT_extensions_string 1
GLAD_API_CALL int SF_GLAD_WGL_EXT_extensions_string;
#define WGL_EXT_framebuffer_sRGB 1
GLAD_API_CALL int SF_GLAD_WGL_EXT_framebuffer_sRGB;
#define WGL_EXT_swap_control 1
GLAD_API_CALL int SF_GLAD_WGL_EXT_swap_control;


typedef int (GLAD_API_PTR *PFNCHOOSEPIXELFORMATPROC)(HDC hDc, const PIXELFORMATDESCRIPTOR * pPfd);
typedef int (GLAD_API_PTR *PFNDESCRIBEPIXELFORMATPROC)(HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR * ppfd);
typedef UINT (GLAD_API_PTR *PFNGETENHMETAFILEPIXELFORMATPROC)(HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR * ppfd);
typedef int (GLAD_API_PTR *PFNGETPIXELFORMATPROC)(HDC hdc);
typedef BOOL (GLAD_API_PTR *PFNSETPIXELFORMATPROC)(HDC hdc, int ipfd, const PIXELFORMATDESCRIPTOR * ppfd);
typedef BOOL (GLAD_API_PTR *PFNSWAPBUFFERSPROC)(HDC hdc);
typedef BOOL (GLAD_API_PTR *PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
typedef BOOL (GLAD_API_PTR *PFNWGLCOPYCONTEXTPROC)(HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask);
typedef HGLRC (GLAD_API_PTR *PFNWGLCREATECONTEXTPROC)(HDC hDc);
typedef HGLRC (GLAD_API_PTR *PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int * attribList);
typedef HGLRC (GLAD_API_PTR *PFNWGLCREATELAYERCONTEXTPROC)(HDC hDc, int level);
typedef HPBUFFERARB (GLAD_API_PTR *PFNWGLCREATEPBUFFERARBPROC)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
typedef BOOL (GLAD_API_PTR *PFNWGLDELETECONTEXTPROC)(HGLRC oldContext);
typedef BOOL (GLAD_API_PTR *PFNWGLDESCRIBELAYERPLANEPROC)(HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd);
typedef BOOL (GLAD_API_PTR *PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB hPbuffer);
typedef HGLRC (GLAD_API_PTR *PFNWGLGETCURRENTCONTEXTPROC)(void);
typedef HDC (GLAD_API_PTR *PFNWGLGETCURRENTDCPROC)(void);
typedef const char * (GLAD_API_PTR *PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC hdc);
typedef const char * (GLAD_API_PTR *PFNWGLGETEXTENSIONSSTRINGEXTPROC)(void);
typedef int (GLAD_API_PTR *PFNWGLGETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
typedef HDC (GLAD_API_PTR *PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer);
typedef BOOL (GLAD_API_PTR *PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues);
typedef BOOL (GLAD_API_PTR *PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues);
typedef PROC (GLAD_API_PTR *PFNWGLGETPROCADDRESSPROC)(LPCSTR lpszProc);
typedef int (GLAD_API_PTR *PFNWGLGETSWAPINTERVALEXTPROC)(void);
typedef BOOL (GLAD_API_PTR *PFNWGLMAKECURRENTPROC)(HDC hDc, HGLRC newContext);
typedef BOOL (GLAD_API_PTR *PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB hPbuffer, int iAttribute, int * piValue);
typedef BOOL (GLAD_API_PTR *PFNWGLREALIZELAYERPALETTEPROC)(HDC hdc, int iLayerPlane, BOOL bRealize);
typedef int (GLAD_API_PTR *PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer, HDC hDC);
typedef int (GLAD_API_PTR *PFNWGLSETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
typedef BOOL (GLAD_API_PTR *PFNWGLSHARELISTSPROC)(HGLRC hrcSrvShare, HGLRC hrcSrvSource);
typedef BOOL (GLAD_API_PTR *PFNWGLSWAPINTERVALEXTPROC)(int interval);
typedef BOOL (GLAD_API_PTR *PFNWGLSWAPLAYERBUFFERSPROC)(HDC hdc, UINT fuFlags);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTBITMAPSPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTBITMAPSAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTBITMAPSWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTOUTLINESPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTOUTLINESAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
typedef BOOL (GLAD_API_PTR *PFNWGLUSEFONTOUTLINESWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);

GLAD_API_CALL PFNWGLCHOOSEPIXELFORMATARBPROC sf_glad_wglChoosePixelFormatARB;
#define wglChoosePixelFormatARB sf_glad_wglChoosePixelFormatARB
GLAD_API_CALL PFNWGLCREATECONTEXTATTRIBSARBPROC sf_glad_wglCreateContextAttribsARB;
#define wglCreateContextAttribsARB sf_glad_wglCreateContextAttribsARB
GLAD_API_CALL PFNWGLCREATEPBUFFERARBPROC sf_glad_wglCreatePbufferARB;
#define wglCreatePbufferARB sf_glad_wglCreatePbufferARB
GLAD_API_CALL PFNWGLDESTROYPBUFFERARBPROC sf_glad_wglDestroyPbufferARB;
#define wglDestroyPbufferARB sf_glad_wglDestroyPbufferARB
GLAD_API_CALL PFNWGLGETEXTENSIONSSTRINGARBPROC sf_glad_wglGetExtensionsStringARB;
#define wglGetExtensionsStringARB sf_glad_wglGetExtensionsStringARB
GLAD_API_CALL PFNWGLGETEXTENSIONSSTRINGEXTPROC sf_glad_wglGetExtensionsStringEXT;
#define wglGetExtensionsStringEXT sf_glad_wglGetExtensionsStringEXT
GLAD_API_CALL PFNWGLGETPBUFFERDCARBPROC sf_glad_wglGetPbufferDCARB;
#define wglGetPbufferDCARB sf_glad_wglGetPbufferDCARB
GLAD_API_CALL PFNWGLGETPIXELFORMATATTRIBFVARBPROC sf_glad_wglGetPixelFormatAttribfvARB;
#define wglGetPixelFormatAttribfvARB sf_glad_wglGetPixelFormatAttribfvARB
GLAD_API_CALL PFNWGLGETPIXELFORMATATTRIBIVARBPROC sf_glad_wglGetPixelFormatAttribivARB;
#define wglGetPixelFormatAttribivARB sf_glad_wglGetPixelFormatAttribivARB
GLAD_API_CALL PFNWGLGETSWAPINTERVALEXTPROC sf_glad_wglGetSwapIntervalEXT;
#define wglGetSwapIntervalEXT sf_glad_wglGetSwapIntervalEXT
GLAD_API_CALL PFNWGLQUERYPBUFFERARBPROC sf_glad_wglQueryPbufferARB;
#define wglQueryPbufferARB sf_glad_wglQueryPbufferARB
GLAD_API_CALL PFNWGLRELEASEPBUFFERDCARBPROC sf_glad_wglReleasePbufferDCARB;
#define wglReleasePbufferDCARB sf_glad_wglReleasePbufferDCARB
GLAD_API_CALL PFNWGLSWAPINTERVALEXTPROC sf_glad_wglSwapIntervalEXT;
#define wglSwapIntervalEXT sf_glad_wglSwapIntervalEXT





#ifdef __cplusplus
}
#endif
#endif

/* Source */
#ifdef SF_GLAD_WGL_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */


int SF_GLAD_WGL_VERSION_1_0 = 0;
int SF_GLAD_WGL_ARB_create_context = 0;
int SF_GLAD_WGL_ARB_create_context_profile = 0;
int SF_GLAD_WGL_ARB_extensions_string = 0;
int SF_GLAD_WGL_ARB_framebuffer_sRGB = 0;
int SF_GLAD_WGL_ARB_multisample = 0;
int SF_GLAD_WGL_ARB_pbuffer = 0;
int SF_GLAD_WGL_ARB_pixel_format = 0;
int SF_GLAD_WGL_EXT_extensions_string = 0;
int SF_GLAD_WGL_EXT_framebuffer_sRGB = 0;
int SF_GLAD_WGL_EXT_swap_control = 0;



PFNWGLCHOOSEPIXELFORMATARBPROC sf_glad_wglChoosePixelFormatARB = NULL;
PFNWGLCREATECONTEXTATTRIBSARBPROC sf_glad_wglCreateContextAttribsARB = NULL;
PFNWGLCREATEPBUFFERARBPROC sf_glad_wglCreatePbufferARB = NULL;
PFNWGLDESTROYPBUFFERARBPROC sf_glad_wglDestroyPbufferARB = NULL;
PFNWGLGETEXTENSIONSSTRINGARBPROC sf_glad_wglGetExtensionsStringARB = NULL;
PFNWGLGETEXTENSIONSSTRINGEXTPROC sf_glad_wglGetExtensionsStringEXT = NULL;
PFNWGLGETPBUFFERDCARBPROC sf_glad_wglGetPbufferDCARB = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC sf_glad_wglGetPixelFormatAttribfvARB = NULL;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC sf_glad_wglGetPixelFormatAttribivARB = NULL;
PFNWGLGETSWAPINTERVALEXTPROC sf_glad_wglGetSwapIntervalEXT = NULL;
PFNWGLQUERYPBUFFERARBPROC sf_glad_wglQueryPbufferARB = NULL;
PFNWGLRELEASEPBUFFERDCARBPROC sf_glad_wglReleasePbufferDCARB = NULL;
PFNWGLSWAPINTERVALEXTPROC sf_glad_wglSwapIntervalEXT = NULL;


static void sf_glad_wgl_load_WGL_ARB_create_context(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_ARB_create_context) return;
    sf_glad_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) load(userptr, "wglCreateContextAttribsARB");
}
static void sf_glad_wgl_load_WGL_ARB_extensions_string(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_ARB_extensions_string) return;
    sf_glad_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) load(userptr, "wglGetExtensionsStringARB");
}
static void sf_glad_wgl_load_WGL_ARB_pbuffer(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_ARB_pbuffer) return;
    sf_glad_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC) load(userptr, "wglCreatePbufferARB");
    sf_glad_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC) load(userptr, "wglDestroyPbufferARB");
    sf_glad_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC) load(userptr, "wglGetPbufferDCARB");
    sf_glad_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC) load(userptr, "wglQueryPbufferARB");
    sf_glad_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC) load(userptr, "wglReleasePbufferDCARB");
}
static void sf_glad_wgl_load_WGL_ARB_pixel_format(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_ARB_pixel_format) return;
    sf_glad_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) load(userptr, "wglChoosePixelFormatARB");
    sf_glad_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC) load(userptr, "wglGetPixelFormatAttribfvARB");
    sf_glad_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) load(userptr, "wglGetPixelFormatAttribivARB");
}
static void sf_glad_wgl_load_WGL_EXT_extensions_string(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_EXT_extensions_string) return;
    sf_glad_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) load(userptr, "wglGetExtensionsStringEXT");
}
static void sf_glad_wgl_load_WGL_EXT_swap_control(GLADuserptrloadfunc load, void *userptr) {
    if(!SF_GLAD_WGL_EXT_swap_control) return;
    sf_glad_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) load(userptr, "wglGetSwapIntervalEXT");
    sf_glad_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) load(userptr, "wglSwapIntervalEXT");
}

static int sf_glad_wgl_has_extension(HDC hdc, const char *ext) {
    const char *terminator;
    const char *loc;
    const char *extensions;

    if(wglGetExtensionsStringEXT == NULL && wglGetExtensionsStringARB == NULL)
        return 0;

    if(wglGetExtensionsStringARB == NULL || hdc == INVALID_HANDLE_VALUE)
        extensions = wglGetExtensionsStringEXT();
    else
        extensions = wglGetExtensionsStringARB(hdc);

    if(extensions == NULL || ext == NULL)
        return 0;

    while(1) {
        loc = strstr(extensions, ext);
        if(loc == NULL)
            break;

        terminator = loc + strlen(ext);
        if((loc == extensions || *(loc - 1) == ' ') &&
            (*terminator == ' ' || *terminator == '\0'))
        {
            return 1;
        }
        extensions = terminator;
    }

    return 0;
}

static GLADapiproc sf_glad_wgl_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int sf_glad_wgl_find_extensions_wgl(HDC hdc) {
    SF_GLAD_WGL_ARB_create_context = sf_glad_wgl_has_extension(hdc, "WGL_ARB_create_context");
    SF_GLAD_WGL_ARB_create_context_profile = sf_glad_wgl_has_extension(hdc, "WGL_ARB_create_context_profile");
    SF_GLAD_WGL_ARB_extensions_string = sf_glad_wgl_has_extension(hdc, "WGL_ARB_extensions_string");
    SF_GLAD_WGL_ARB_framebuffer_sRGB = sf_glad_wgl_has_extension(hdc, "WGL_ARB_framebuffer_sRGB");
    SF_GLAD_WGL_ARB_multisample = sf_glad_wgl_has_extension(hdc, "WGL_ARB_multisample");
    SF_GLAD_WGL_ARB_pbuffer = sf_glad_wgl_has_extension(hdc, "WGL_ARB_pbuffer");
    SF_GLAD_WGL_ARB_pixel_format = sf_glad_wgl_has_extension(hdc, "WGL_ARB_pixel_format");
    SF_GLAD_WGL_EXT_extensions_string = sf_glad_wgl_has_extension(hdc, "WGL_EXT_extensions_string");
    SF_GLAD_WGL_EXT_framebuffer_sRGB = sf_glad_wgl_has_extension(hdc, "WGL_EXT_framebuffer_sRGB");
    SF_GLAD_WGL_EXT_swap_control = sf_glad_wgl_has_extension(hdc, "WGL_EXT_swap_control");
    return 1;
}

static int sf_glad_wgl_find_core_wgl(void) {
    int major = 1, minor = 0;
    SF_GLAD_WGL_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    return GLAD_MAKE_VERSION(major, minor);
}

static int gladLoadWGLUserPtr(HDC hdc, GLADuserptrloadfunc load, void *userptr) {
    int version;
    wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) load(userptr, "wglGetExtensionsStringARB");
    wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC) load(userptr, "wglGetExtensionsStringEXT");
    if(wglGetExtensionsStringARB == NULL && wglGetExtensionsStringEXT == NULL) return 0;
    version = sf_glad_wgl_find_core_wgl();


    if (!sf_glad_wgl_find_extensions_wgl(hdc)) return 0;
    sf_glad_wgl_load_WGL_ARB_create_context(load, userptr);
    sf_glad_wgl_load_WGL_ARB_extensions_string(load, userptr);
    sf_glad_wgl_load_WGL_ARB_pbuffer(load, userptr);
    sf_glad_wgl_load_WGL_ARB_pixel_format(load, userptr);
    sf_glad_wgl_load_WGL_EXT_extensions_string(load, userptr);
    sf_glad_wgl_load_WGL_EXT_swap_control(load, userptr);

    return version;
}

static int gladLoadWGL(HDC hdc, GLADloadfunc load) {
    return gladLoadWGLUserPtr(hdc, sf_glad_wgl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}

#endif /* SF_GLAD_WGL_IMPLEMENTATION */
