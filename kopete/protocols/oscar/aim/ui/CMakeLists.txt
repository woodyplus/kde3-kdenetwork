#################################################
#
#  (C) 2010-2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_CURRENT_SOURCE_DIR}/../..
  ${CMAKE_CURRENT_SOURCE_DIR}/../../liboscar
  ${CMAKE_BINARY_DIR}/kopete/libkopete/ui
  ${CMAKE_SOURCE_DIR}/kopete/libkopete
  ${CMAKE_SOURCE_DIR}/kopete/libkopete/ui
  ${KDE_INCLUDE_DIR}
  ${QT_INCLUDE_DIR}
)


##### kopeteaimui (static) ######################

kde_add_library( kopeteaimui STATIC_PIC AUTOMOC
  SOURCES
    aimaddcontactui.ui aimeditaccountui.ui aiminfobase.ui
    aimjoinchatbase.ui aimaddcontactpage.cpp aimeditaccountwidget.cpp
)
