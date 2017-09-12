watch('src/(.*)\.[c|cpp]') { |filename| system "cd build && make && make test && cd .."}
watch('include/(.*)\.[h|hpp]') { |filename| system "cd build && make && make test && cd .."}
watch('tests/(.*)\.[c|cpp|h|hpp]') { |filename| system "cd build && make && make test && cd .."}
