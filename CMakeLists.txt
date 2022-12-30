cmake_minimum_required(VERSION 3.19)


project(freeverb3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(freeverb_sources
	freeverb/allpass.cpp
	freeverb/biquad.cpp
	freeverb/blockDelay.cpp
	freeverb/comb.cpp
	freeverb/compmodel.cpp
	freeverb/delay.cpp
	freeverb/delayline.cpp
	freeverb/dl_gardner.cpp
	freeverb/earlyref.cpp
	freeverb/efilter.cpp
	freeverb/fir3bandsplit.cpp
	freeverb/firfilter.cpp
	freeverb/firwindow.cpp
	freeverb/frag.cpp
	freeverb/irbase.cpp
	freeverb/irmodel1.cpp
	freeverb/irmodel2.cpp
	freeverb/irmodel2zl.cpp
	freeverb/irmodel3.cpp
	freeverb/irmodel3p.cpp
	freeverb/irmodels.cpp
	freeverb/limitmodel.cpp
	freeverb/mls.cpp
	freeverb/nrev.cpp
	freeverb/nrevb.cpp
	freeverb/progenitor.cpp
	freeverb/progenitor2.cpp
	freeverb/revbase.cpp
	freeverb/revmodel.cpp
	freeverb/rms.cpp
	freeverb/scomp.cpp
	freeverb/slimit.cpp
	freeverb/slot.cpp
	freeverb/src.cpp
	freeverb/stenh.cpp
	freeverb/strev.cpp
	freeverb/sweep.cpp
	freeverb/utils.cpp
	freeverb/zrev.cpp
	freeverb/zrev2.cpp
)

set(freeverb_headers
	freeverb/allpass.hpp 
	freeverb/allpass_t.hpp 
	freeverb/biquad.hpp 
	freeverb/biquad_t.hpp 
	freeverb/blockDelay.hpp 
	freeverb/blockDelay_t.hpp 
	freeverb/comb.hpp 
	freeverb/comb_t.hpp 
	freeverb/compmodel.hpp 
	freeverb/compmodel_t.hpp 
	freeverb/delay.hpp 
	freeverb/delay_t.hpp 
	freeverb/delayline.hpp 
	freeverb/delayline_t.hpp 
	freeverb/dl_gardner.hpp 
	freeverb/dl_gardner_t.hpp 
	freeverb/earlyref.hpp 
	freeverb/earlyref_t.hpp 
	freeverb/efilter.hpp 
	freeverb/efilter_t.hpp 
	freeverb/fir3bandsplit.hpp 
	freeverb/fir3bandsplit_t.hpp 
	freeverb/firfilter.hpp 
	freeverb/firfilter_t.hpp 
	freeverb/firwindow.hpp 
	freeverb/firwindow_t.hpp
	freeverb/frag.hpp 
	freeverb/frag_t.hpp 
	freeverb/fv3_ch_tool.hpp 
	freeverb/fv3_defs.h 
	freeverb/fv3_ns_end.h 
	freeverb/fv3_ns_start.h 
	freeverb/fv3_pthread_tool.hpp 
	freeverb/fv3_type_float.h 
	freeverb/irbase.hpp 
	freeverb/irbase_t.hpp 
	freeverb/irmodel1.hpp 
	freeverb/irmodel1_t.hpp 
	freeverb/irmodel2.hpp 
	freeverb/irmodel2_t.hpp 
	freeverb/irmodel2zl.hpp 
	freeverb/irmodel2zl_t.hpp 
	freeverb/irmodel3.hpp 
	freeverb/irmodel3_t.hpp 
	freeverb/irmodel3p.hpp 
	freeverb/irmodel3p_t.hpp 
	freeverb/irmodels.hpp 
	freeverb/irmodels_t.hpp 
	freeverb/limitmodel.hpp 
	freeverb/limitmodel_t.hpp 
	freeverb/mls.hpp 
	freeverb/mls_t.hpp 
	freeverb/revbase.hpp 
	freeverb/revbase_t.hpp 
	freeverb/nrev.hpp 
	freeverb/nrev_t.hpp 
	freeverb/nrevb.hpp 
	freeverb/nrevb_t.hpp 
	freeverb/progenitor.hpp 
	freeverb/progenitor_t.hpp 
	freeverb/progenitor2.hpp 
	freeverb/progenitor2_t.hpp
	freeverb/revmodel.hpp 
	freeverb/revmodel_t.hpp 
	freeverb/rms.hpp 
	freeverb/rms_t.hpp 
	freeverb/scomp.hpp 
	freeverb/scomp_t.hpp 
	freeverb/sweep.hpp 
	freeverb/sweep_t.hpp 
	freeverb/slimit.hpp 
	freeverb/slimit_t.hpp 
	freeverb/slot.hpp 
	freeverb/slot_t.hpp 
	freeverb/src.hpp 
	freeverb/src_t.hpp 
	freeverb/stenh.hpp 
	freeverb/stenh_t.hpp 
	freeverb/strev.hpp 
	freeverb/strev_t.hpp 
	freeverb/utils.hpp 
	freeverb/utils_t.hpp 
	freeverb/zrev_t.hpp 
	freeverb/zrev.hpp 
	freeverb/zrev2_t.hpp 
	freeverb/zrev2.hpp
	fftw-3.3.10/api/fftw3.h
)

add_library(freeverb SHARED ${freeverb_sources} ${freeverb_headers})

add_compile_definitions(LIBFV3_DEFAULT)
add_compile_definitions(LIBFV3_FLOAT)
add_compile_definitions(LIBSRATE2_FLOAT)
add_compile_definitions(HAVE_CONFIG_H)

target_include_directories(freeverb PRIVATE freeverb)
target_include_directories(freeverb PRIVATE libsamplerate2)
target_include_directories(freeverb PRIVATE libgdither)
target_include_directories(freeverb PRIVATE .)

option(BUILD_TESTS "" OFF)
option(BUILD_SHARED_LIBS "" ON)
option(ENABLE_THREADS "" ON)
add_subdirectory(fftw-3.3.10)
target_include_directories(freeverb PRIVATE fftw-3.3.10/api)

target_link_libraries(freeverb PRIVATE fftw3)
target_link_libraries(freeverb PRIVATE fftw3_threads)

#set(CMAKE_VERBOSE_MAKEFILE ON)

#target_compile_features(DynamicMusicGen_exe PRIVATE cxx_std_17)
#target_compile_features(DynamicMusicGen PRIVATE cxx_std_17)
