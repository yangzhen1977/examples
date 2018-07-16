#!/usr/bin/env ruby

r=require './sub_module.rb'
puts "r is #{r}"
r=require './sub_module.rb'
puts "r is #{r}"

r=require_relative 'sub_module'
puts "r is #{r}"
r=require_relative 'sub_module'
puts "r is #{r}"

r=require_relative 'sub_module.rb'
puts "r is #{r}"
r=require_relative 'sub_module.rb'
puts "r is #{r}"