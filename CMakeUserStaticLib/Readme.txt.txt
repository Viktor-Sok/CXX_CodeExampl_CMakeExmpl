How to create your static library and use it in yuor project at the same time

I assume you are having issues understanding how builds work. I'll try to help you fill in the gaps.

A target is an executable or a library built by cmake.

When creating a library A you need to provide an API (header/include files) and compiled code (.lib).

To use library A in project B, you need to include the header files. You can then compile B. However to create a binary you need to link with the compiled A.

target_include_directories tells cmake where to find the API header files so you can include them from B.

target_link_directories and target_link_libraries tell cmake where to find the library's compiled code. If the library is header-only there is no need to link.