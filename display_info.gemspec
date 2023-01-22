Gem::Specification.new do |s|
  s.name        = "display_info"
  s.version     = "0.0.1"
  s.summary     = "Retrieve info about connected displays"
  s.description = "C extension to natively query the connected displays"
  s.authors     = ["Andy Clink"]
  s.email       = "andy@aravaiparunning.com"
  s.files       = ['lib/display_info.rb']
  s.files      += Dir['ext/display_info/**.c']
  s.homepage    = "http://github.com/aravaiparunning/display_info"
  s.license     = "GPL-3.0"
  s.extensions = %w[ext/display_info/extconf.rb]
end