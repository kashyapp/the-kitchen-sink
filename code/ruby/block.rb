#!/usr/bin/env ruby

class Array
  def mogrify
	if block_given?; yield('hello world') end
	puts "bad world"
  end
end

foo = [1,2,3]
foo.mogrify do |pong|
  puts pong, "baddie"
end
foo.mogrify
