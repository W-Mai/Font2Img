project('Font2Img', 'cpp',
        version : '0.1',
        default_options : ['warning_level=3',
                           'cpp_std=c++17'])

freetype2_dep = dependency('freetype2')

exe = executable('Font2Img', 'font2img.cpp',
                 install : true,
                 dependencies : [freetype2_dep]
)

test('basic', exe)
