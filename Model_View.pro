QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddDialog.cpp \
    Model.cpp \
    libs/utils.cpp \
    main.cpp \
    MainWindow.cpp \
    src/AddDialog.cpp \
    src/MainWindow.cpp \
    src/Model.cpp \
    src/main.cpp \
    utils.cpp

HEADERS += \
    AddDialog.h \
    MainWindow.h \
    Model.h \
    include/AddDialog.h \
    include/MainWindow.h \
    include/Model.h \
    libs/nlohmann/adl_serializer.hpp \
    libs/nlohmann/byte_container_with_subtype.hpp \
    libs/nlohmann/detail/abi_macros.hpp \
    libs/nlohmann/detail/conversions/from_json.hpp \
    libs/nlohmann/detail/conversions/to_chars.hpp \
    libs/nlohmann/detail/conversions/to_json.hpp \
    libs/nlohmann/detail/exceptions.hpp \
    libs/nlohmann/detail/hash.hpp \
    libs/nlohmann/detail/input/binary_reader.hpp \
    libs/nlohmann/detail/input/input_adapters.hpp \
    libs/nlohmann/detail/input/json_sax.hpp \
    libs/nlohmann/detail/input/lexer.hpp \
    libs/nlohmann/detail/input/parser.hpp \
    libs/nlohmann/detail/input/position_t.hpp \
    libs/nlohmann/detail/iterators/internal_iterator.hpp \
    libs/nlohmann/detail/iterators/iter_impl.hpp \
    libs/nlohmann/detail/iterators/iteration_proxy.hpp \
    libs/nlohmann/detail/iterators/iterator_traits.hpp \
    libs/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    libs/nlohmann/detail/iterators/primitive_iterator.hpp \
    libs/nlohmann/detail/json_pointer.hpp \
    libs/nlohmann/detail/json_ref.hpp \
    libs/nlohmann/detail/macro_scope.hpp \
    libs/nlohmann/detail/macro_unscope.hpp \
    libs/nlohmann/detail/meta/call_std/begin.hpp \
    libs/nlohmann/detail/meta/call_std/end.hpp \
    libs/nlohmann/detail/meta/cpp_future.hpp \
    libs/nlohmann/detail/meta/detected.hpp \
    libs/nlohmann/detail/meta/identity_tag.hpp \
    libs/nlohmann/detail/meta/is_sax.hpp \
    libs/nlohmann/detail/meta/std_fs.hpp \
    libs/nlohmann/detail/meta/type_traits.hpp \
    libs/nlohmann/detail/meta/void_t.hpp \
    libs/nlohmann/detail/output/binary_writer.hpp \
    libs/nlohmann/detail/output/output_adapters.hpp \
    libs/nlohmann/detail/output/serializer.hpp \
    libs/nlohmann/detail/string_concat.hpp \
    libs/nlohmann/detail/string_escape.hpp \
    libs/nlohmann/detail/value_t.hpp \
    libs/nlohmann/json.hpp \
    libs/nlohmann/json_fwd.hpp \
    libs/nlohmann/ordered_map.hpp \
    libs/nlohmann/thirdparty/hedley/hedley.hpp \
    libs/nlohmann/thirdparty/hedley/hedley_undef.hpp \
    libs/utils.h \
    nlohmann/adl_serializer.hpp \
    nlohmann/byte_container_with_subtype.hpp \
    nlohmann/detail/abi_macros.hpp \
    nlohmann/detail/conversions/from_json.hpp \
    nlohmann/detail/conversions/to_chars.hpp \
    nlohmann/detail/conversions/to_json.hpp \
    nlohmann/detail/exceptions.hpp \
    nlohmann/detail/hash.hpp \
    nlohmann/detail/input/binary_reader.hpp \
    nlohmann/detail/input/input_adapters.hpp \
    nlohmann/detail/input/json_sax.hpp \
    nlohmann/detail/input/lexer.hpp \
    nlohmann/detail/input/parser.hpp \
    nlohmann/detail/input/position_t.hpp \
    nlohmann/detail/iterators/internal_iterator.hpp \
    nlohmann/detail/iterators/iter_impl.hpp \
    nlohmann/detail/iterators/iteration_proxy.hpp \
    nlohmann/detail/iterators/iterator_traits.hpp \
    nlohmann/detail/iterators/json_reverse_iterator.hpp \
    nlohmann/detail/iterators/primitive_iterator.hpp \
    nlohmann/detail/json_pointer.hpp \
    nlohmann/detail/json_ref.hpp \
    nlohmann/detail/macro_scope.hpp \
    nlohmann/detail/macro_unscope.hpp \
    nlohmann/detail/meta/call_std/begin.hpp \
    nlohmann/detail/meta/call_std/end.hpp \
    nlohmann/detail/meta/cpp_future.hpp \
    nlohmann/detail/meta/detected.hpp \
    nlohmann/detail/meta/identity_tag.hpp \
    nlohmann/detail/meta/is_sax.hpp \
    nlohmann/detail/meta/std_fs.hpp \
    nlohmann/detail/meta/type_traits.hpp \
    nlohmann/detail/meta/void_t.hpp \
    nlohmann/detail/output/binary_writer.hpp \
    nlohmann/detail/output/output_adapters.hpp \
    nlohmann/detail/output/serializer.hpp \
    nlohmann/detail/string_concat.hpp \
    nlohmann/detail/string_escape.hpp \
    nlohmann/detail/value_t.hpp \
    nlohmann/json.hpp \
    nlohmann/json_fwd.hpp \
    nlohmann/ordered_map.hpp \
    nlohmann/thirdparty/hedley/hedley.hpp \
    nlohmann/thirdparty/hedley/hedley_undef.hpp \
    utils.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    icons.qrc \
    res/icons.qrc \
    res/icons.qrc

DISTFILES += \
    123.json \
    CMakeLists.txt \
    file.json \
    icons/cross.svg \
    icons/load.svg \
    icons/negative.svg \
    icons/phone.svg \
    icons/positive.svg \
    icons/save.svg \
    icons/search.svg
