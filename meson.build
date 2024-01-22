project('Font2Img', 'cpp',
        version : '0.1',
        default_options : [
            'warning_level=3',
            'cpp_std=c++17',
            '-DFT2_BUILD_LIBRARY=1'
        ])

freetype2_dep = dependency('freetype2')

cpp_source = files('src/Freetype.cpp', 'src/Freetype.h')

exe = executable('Font2Img', cpp_source + 'font2img.cpp',
                 install : true,
                 dependencies : [freetype2_dep]
)

test('basic', exe)
