add_executable(CLI
  main.cpp
)

#target_link_libraries(CLI PRIVATE
#  JobSchedulerCore
#)

install(TARGETS CLI DESTINATION bin)
