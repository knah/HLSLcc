#include "hlslcc.h"

extern "C" {
HLSLCC_API int HLSLCC_APIENTRY TranslateHLSLFromMemSimple(const char* shader,
                                                    unsigned int flags,
                                                    GLLang language,
                                                    GlExtensions extensions,
                                                    GLSLShader* result) {
    auto precisionInfo = HLSLccSamplerPrecisionInfo();
    auto reflection = HLSLccReflection();
    return TranslateHLSLFromMem(shader, flags, language, &extensions, nullptr, precisionInfo, reflection, result);
}

HLSLCC_API int HLSLCC_APIENTRY GetShaderCodeLength(GLSLShader* shader) {
    return shader->sourceCode.length();
}

HLSLCC_API const char* HLSLCC_APIENTRY GetShaderCodeChars(GLSLShader* shader) {
    return shader->sourceCode.c_str();
}

HLSLCC_API GLSLShader* HLSLCC_APIENTRY AllocShader() {
    return new GLSLShader();
}

HLSLCC_API void HLSLCC_APIENTRY FreeShader(GLSLShader* shader) {
    delete shader;
}

}