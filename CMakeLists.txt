#
# @BEGIN LICENSE
#
# rhf_dlmg2b by Psi4 Developer, a plugin to:
#
# Psi4: an open-source quantum chemistry software package
#
# Copyright (c) 2007-2017 The Psi4 Developers.
#
# The copyrights for code used from other parties are included in
# the corresponding files.
#
# This file is part of Psi4.
#
# Psi4 is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, version 3.
#
# Psi4 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with Psi4; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# @END LICENSE
#

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(rhf_dlmg2b CXX)

find_package(psi4 1.1 REQUIRED)

#SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -g -lgfortran")
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -O3 -lgfortran")
SET( CMAKE_POSITION_INDEPENDENT_CODE ON)

add_psi4_plugin(rhf_dlmg2b plugin.cc rhfdlmg2b.cc myelst.cc)

target_link_libraries(rhf_dlmg2b LINK_PRIVATE /home/jchoward/newriver/dlmg2/dl_mg_v2.0.0rc17/lib/libdlmg.a)

