# 介绍

这是一个只使用 CMake 和 Google Test 来构建并执行自动化测试用例的示例程序。


# 文件目录结构

- `build/` 用于构建代码的目录 - 类似于可执行文件的存放地。
- `lib/` 包含了gtest-1.6.0库。
- `CMakeLists.txt` 必须在项目的每个子目录中都存在。
- `src`
  - `main.cpp` 是入口文件 - 通常用于运行常规应用程序。
  - `myfoo.cpp` 和 `myfoo.h` 包含类 `MyFoo` 的代码。
- `test`
  - `test_MyFoo.cpp` 包含测试代码。

# 怎么做？

## 如何构建可执行文件

在项目根目录执行下面的命令：

```bash
rm -rf build && mkdir build && cd build &&cmake .. && make &&  ./myfoo
```

上面的命令

- 首先创建了一个新的 build 子目录，
- 然后通过 `cmake ..` 创建 Makefiles
- 再通过 `make` 进行编译与所有链接工作，生成可执行文件 `./myfoo`
- 最后 在 `build` 子目录下运行可执行文件 `./myfoo`


## 如何构建并执行测试用例

要准备所有测试，请运行以下命令：

```bash

rm -rf build && mkdir build && cd build &&cmake -Dtest=ON .. && make &&  ./runUnitTests

```

上面的命令：

- 首先创建了一个新的 build 子目录，
- 然后通过 `cmake ..` 创建 Makefiles
- 再通过 `make` 进行编译与所有链接工作，生成可执行文件 `./runUnitTests`
- 最后 在 `build` 子目录下运行可执行文件 `./runUnitTests`

## 如何生成测试覆盖率

要准备所有测试，请运行以下命令：

```bash

rm -rf build && mkdir build && cd build &&cmake -Dtest=ON -DENABLE_COVERAGE=ON .. && make &&  ./runUnitTests
lcov --capture --no-external --demangle-cpp --directory ./CMakeFiles/myfoo_lib.dir/src/ --base-directory ../src   --output-file coverage_base.info
lcov --summary coverage_base.info
genhtml coverage_base.info --output-directory coverage --quiet
```

上面的命令：

- 第一行命令：打开 Coverage 开关，并运行测试执行文件，从而生成 .gcno 和 .gcda 文件。
- 第二行命令：通过参数 `--directory ./CMakeFiles/myfoo_lib.dir/src/` 指定需要统计其覆盖率的文件目录，将所有 .gcno 和 .gcda 文件中的信息抽取出来，并生成结果文件 `coverage_base.info`
- 第三行命令：总结并打印出覆盖率的结果
- 第四行命令：创建目录 `coverage` ，并使用 `coverage_base.info` 的信息在 `coverage` 目录下生成 HTML 报告文件。


# 详情

## 命令选项
`cmake -Dtest=ON` 开启了变量 'test'，这个变量在根目录的 `CMakeLists.txt` 文件中指定。如果您想以特定的方式进行构建，这很有用。关于这个选项的清晰描述，请查看[此处](http://stackoverflow.com/questions/5998186/cmake-adding-command-line-options)。

## 我的经验

我花了很多时间来弄清楚如何引用 gtest 库。
最后，我选择在每个使用 gtest 的应用程序中使用 gtest 的复本。

[这个用户的编辑过的解决方案](http://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake)和[这个回答](http://stackoverflow.com/questions/14148145/gtest-detects-method-only-when-the-method-is-implemented-in-h-not-in-cpp-cma/14157405#14157405)帮助了我。