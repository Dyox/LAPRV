// -*- mode: c++ -*- (automatically generated)

#ifndef _com_moesol_bindings_platform_sdk_windows_api_HFONT_h_included
#define _com_moesol_bindings_platform_sdk_windows_api_HFONT_h_included

// super class
#include "com/moesol/bindings/platform_sdk/windows_api/HGDIOBJ.h"

// forward declarations
namespace com { namespace moesol { namespace bindings { namespace platform_1sdk { namespace windows_1api { class HFONT; }  }  }  }  } 
namespace com { namespace moesol { namespace bindings { namespace platform_1sdk { namespace windows_1api { class LOGFONT; }  }  }  }  } 


namespace com { namespace moesol { namespace bindings { namespace platform_1sdk { namespace windows_1api { 

    class HFONT : public ::com::moesol::bindings::platform_1sdk::windows_1api::HGDIOBJ {
    public:
        static void *operator new(size_t size, ::com::moesol::bindings::jni_env *env) {
            _ASSERT(size <= sizeof(4));
            return env->alloc_object( static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0)) );
        }
        static jclass static_class(::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::impl_marker * = 0) {
            static ::com::moesol::bindings::jclass_cache class_cache;
            return class_cache.forName(env, "com/moesol/bindings/platform_sdk/windows_api/HFONT");
        }
        // TODO support for java_array<Foo> a;
        // operators for each interface
        
   		// BEGIN h.ctor.tmpl
        HFONT( ::com::moesol::bindings::jni_env *env, jlong p0 ) {
            static ::com::moesol::bindings::jmethodID_cache mid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jmethodID mid = mid_cache.get_method_id(env, cls,
                "<init>", "(J)V");

            env->call_nonvirtual_method( static_cast<void *>(0), this, cls, mid, p0 );
        }
        // END h.ctor.tmpl
   		// BEGIN h.ctor.tmpl
        HFONT( ::com::moesol::bindings::jni_env *env, jlong p0, jboolean p1 ) {
            static ::com::moesol::bindings::jmethodID_cache mid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jmethodID mid = mid_cache.get_method_id(env, cls,
                "<init>", "(JZ)V");

            env->call_nonvirtual_method( static_cast<void *>(0), this, cls, mid, p0, p1 );
        }
        // END h.ctor.tmpl
 		// BEGIN h.method.static.tmpl
        // public static
        static ::com::moesol::bindings::platform_1sdk::windows_1api::HFONT * createFontIndirect( ::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::platform_1sdk::windows_1api::LOGFONT * p0, ::com::moesol::bindings::method_marker * = 0 ) {
            static ::com::moesol::bindings::jmethodID_cache mid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jmethodID mid = mid_cache.get_static_method_id(env, cls,
                "createFontIndirect", "(Lcom/moesol/bindings/platform_sdk/windows_api/LOGFONT;)Lcom/moesol/bindings/platform_sdk/windows_api/HFONT;");

            return (::com::moesol::bindings::platform_1sdk::windows_1api::HFONT *)
                ::com::moesol::bindings::call_static_method<jobject>( env, cls, mid, p0 );
        }
 		// END h.method.static.tmpl
		// BEGIN h.method.native.static.tmpl
        // private static
        static jlong jni_createFontIndirect( ::com::moesol::bindings::jni_env *env, jbyteArray p0, ::com::moesol::bindings::method_marker * = 0 ) { 
            static ::com::moesol::bindings::jmethodID_cache mid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jmethodID mid = mid_cache.get_static_method_id(env, cls,
                "jni_createFontIndirect", "([B)J");

            return (jlong)
                ::com::moesol::bindings::call_static_method<jlong>( env, cls, mid, p0 );
        }
        static jlong jni_createFontIndirect_thunk ( ::com::moesol::bindings::jni_env *e, jclass self, jbyteArray p0 ) {
            try {
                return  jni_createFontIndirect_impl( e, self, p0 );
            } catch (::java::lang::Throwable *t) {
                e->throw_object(t);
                return 0;
            }
        }
        static jlong jni_createFontIndirect_impl( ::com::moesol::bindings::jni_env *e, jclass self, jbyteArray p0 );
		// END h.method.native.static.tmpl
// BEGIN h.field.static.tmpl
#ifndef ANSI_CHARSET_
        // public static final
        static ::com::moesol::bindings::java_static_field<jbyte, jbyte>
        ANSI_CHARSET_(::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::field_marker * = 0) {
            static ::com::moesol::bindings::jfieldID_cache fid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jfieldID fid = fid_cache.get_static_field_id(env, cls,
                "ANSI_CHARSET", "B");

            return ::com::moesol::bindings::java_static_field<jbyte, jbyte>(env, cls, fid);
        }
#endif
// END h.field.static.tmpl
// BEGIN h.field.static.tmpl
#ifndef DEFAULT_CHARSET_
        // public static final
        static ::com::moesol::bindings::java_static_field<jbyte, jbyte>
        DEFAULT_CHARSET_(::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::field_marker * = 0) {
            static ::com::moesol::bindings::jfieldID_cache fid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jfieldID fid = fid_cache.get_static_field_id(env, cls,
                "DEFAULT_CHARSET", "B");

            return ::com::moesol::bindings::java_static_field<jbyte, jbyte>(env, cls, fid);
        }
#endif
// END h.field.static.tmpl
// BEGIN h.field.static.tmpl
#ifndef SYMBOL_CHARSET_
        // public static final
        static ::com::moesol::bindings::java_static_field<jbyte, jbyte>
        SYMBOL_CHARSET_(::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::field_marker * = 0) {
            static ::com::moesol::bindings::jfieldID_cache fid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jfieldID fid = fid_cache.get_static_field_id(env, cls,
                "SYMBOL_CHARSET", "B");

            return ::com::moesol::bindings::java_static_field<jbyte, jbyte>(env, cls, fid);
        }
#endif
// END h.field.static.tmpl
// BEGIN h.field.static.tmpl
#ifndef OEM_CHARSET_
        // public static final
        static ::com::moesol::bindings::java_static_field<jbyte, jbyte>
        OEM_CHARSET_(::com::moesol::bindings::jni_env *env, ::com::moesol::bindings::field_marker * = 0) {
            static ::com::moesol::bindings::jfieldID_cache fid_cache;
            jclass cls = static_class(env, static_cast<::com::moesol::bindings::impl_marker *>(0));
            jfieldID fid = fid_cache.get_static_field_id(env, cls,
                "OEM_CHARSET", "B");

            return ::com::moesol::bindings::java_static_field<jbyte, jbyte>(env, cls, fid);
        }
#endif
// END h.field.static.tmpl

    protected:
        /**
         * Constructor chaining happens on the Java side. Derived
         * classes call the base class ctor(void) to skip C++ chaining
         * effects (all ctor(void) methods are do nothing).
         */
        HFONT() {
        }
        /**
         * Making the destructor protected, prevents local (stack
         * based) declarations of this class.  Also, prevents deleting
         * new'ed instances (which actually get GC'ed by Java). Note
         * this method is never actually called.
         */
        ~HFONT() {
        }

    };

} } } } } 

#endif


#ifdef include_HFONT_registration

namespace com { namespace moesol { namespace bindings { namespace platform_1sdk { namespace windows_1api { 

JNINativeMethod HFONT_reg_methods[] = {
    { "jni_createFontIndirect",
      "([B)J",
      HFONT::jni_createFontIndirect_thunk },

};
::com::moesol::bindings::jni_registration HFONT_registration("com/moesol/bindings/platform_sdk/windows_api/HFONT",
    HFONT_reg_methods, sizeof(HFONT_reg_methods)/sizeof(HFONT_reg_methods[0]));

} } } } } 

#endif
