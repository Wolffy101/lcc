set(TEST_NAME c100_test)
project(${TEST_NAME})

aux_source_directory(. TEST_LIST)
find_package(Catch2 CONFIG REQUIRED)

add_executable(${TEST_NAME} ${TEST_LIST})

target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
target_link_libraries(${TEST_NAME} PRIVATE ${MAIN_LIB})
#注意这里
add_test(
	NAME ${TEST_NAME} 
	COMMAND $<TARGET_FILE:${TEST_NAME}> --success
	)