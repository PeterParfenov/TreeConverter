set(TCUtility_header_files
  TCConstants.h
)
set(TCUtility_cxx_files
  TCConstants.cxx
)

#---Generate dictionary for TCUtility
ROOT_GENERATE_DICTIONARY(G__TCUtility
${TCUtility_header_files}
LINKDEF TCUtility.LinkDef.h)

add_library(TCUtility SHARED
${TCUtility_cxx_files}
G__TCUtility.cxx)

target_link_libraries(TCUtility)