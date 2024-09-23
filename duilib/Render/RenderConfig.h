#ifndef UI_RENDER_RENDER_CONFIG_H_
#define UI_RENDER_RENDER_CONFIG_H_

//定义这个宏，表示使用LLVM编译Skia，否则表示使用Visual Studio 2022编译Skia
#define DUILIB_RENDER_SKIA_BY_LLVM  1


//备注：
//1、性能方面：LLVM编译的版本，性能明显好于Visual Studio 2022编译的版本。
//（1）LLVM编译的Debug版本，可以流畅运行，感觉不到卡顿现象；
//（2）Visual Studio 2022编译Debug版本，运行明显卡顿，速度很慢。有GIF动画时，感觉跑不动。
//2、兼容性方面：
//（1）Visual Studio 2022编译的版本，Debug和Release都没有问题；
//（2）DebugLLVM 版本有问题，对于部分智能指针的赋值接口，程序会崩溃；ReleaseLLVM暂时没发现问题。
//     比如void SkPaint::setShader(sk_sp<SkShader> shader);
//     需要改为：void SkPaint::setShader(const sk_sp<SkShader>& shader); 才能避免崩溃
//     这种类型的接口比较多，如果想要使用，就需要修改源码，然后重新编译Skia。

//Skia引擎需要依赖
#ifdef DUILIB_BUILD_FOR_WIN
    #pragma comment (lib, "opengl32.lib")
    #pragma comment (lib, "skia.lib")
#endif


#endif // UI_RENDER_RENDER_CONFIG_H_
