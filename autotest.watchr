watch('src/(.*)\.[c|cpp]') { |filename| system "cd build && make && ./test_blocky && cd .."}
watch('include/(.*)\.[h|hpp]') { |filename| system "cd build && make && ./test_blocky && cd .."}
watch('tests/(.*)\.[c|cpp|h|hpp]') { |filename| system "cd build && make && ./test_blocky && cd .."}
