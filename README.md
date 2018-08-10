# Tess

A clone of 2048 played on a tesseract, or 4D cube. Match coloured tiles to make better tiles, with 4 degrees of freedom. 
Built using OpenGL 3.3

## Building
This project was built with Visual Studio 2017, but using the Visual Studio 2015 tool set (v140). It depends on GLFW for windowing and events, and GL3W for function loading. Pre-compiled 32-bit and 64-bit libs for these are in the lib folder, but if you want to compile with a different VS version you'll need to recompile the libs yourself.

## Todo
- Colors look wrong on cards that don't support SRGB framebuffer - need to make gamma-correction shader for fallback.  
- Core game logic could be optimized more - less array copying.
- Resizable window.
