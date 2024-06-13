# Install script for directory: /home/decortja/bcl_clone/bcl/apps

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "AppsStatic" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe"
         RPATH ".")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/decortja/bcl_clone/bcl/cmake-build-debug/bin/bcl-apps-static.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe"
         OLD_RPATH "/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/bzip2/1.0.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/zlib/1.2.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/freeocl/0.3.6/lib:"
         NEW_RPATH ".")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps-static.exe")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "AppsDynamic" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe"
         RPATH ".")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/decortja/bcl_clone/bcl/cmake-build-debug/bin/bcl-apps.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe"
         OLD_RPATH "/home/decortja/bcl_clone/bcl/cmake-build-debug/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/bzip2/1.0.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/zlib/1.2.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/freeocl/0.3.6/lib:"
         NEW_RPATH ".")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bcl-apps.exe")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/descriptor/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/internal/biology/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/internal/chemistry/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/internal/util/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/model/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/molecule/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/restraint/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/release/cmake_install.cmake")

endif()

