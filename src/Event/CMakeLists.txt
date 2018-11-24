set(TCEvent_header_files
  TCParticle.h
  TCEvent.h
)
set(TCEvent_cxx_files
  TCParticle.cxx
  TCEvent.cxx
)

#---Generate dictionary for TCEvent
ROOT_GENERATE_DICTIONARY(G__TCEvent
${TCEvent_header_files}
LINKDEF TCEvent.LinkDef.h)

add_library(TCEvent SHARED
${TCEvent_cxx_files}
G__TCEvent.cxx)

target_link_libraries(TCEvent TCUtility)