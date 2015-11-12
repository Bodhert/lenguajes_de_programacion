
Gem::Specification.new do |s|
  s.name    = 'calc'
  s.version = '0.0.1'
  s.date    = '2015-10-29'
  s.summary = 'Another calculator in ruby'
  s.description = 'An calculator implementation on ruby'
  s.author  = 'Kent D. Lee - Juan Francisco Cardona Mc - Alejandro Cordoba Bodhert'
  s.email   = 'acordob5@eafit.edu.co'
  s.homepage = 'http://www1.eafit.edu.co/fcardona/cursos/st0244/rubycal'
  s.files    = ["lib/token.rb",
                "lib/scanner.rb",
                "lib/ast.rb",
                "lib/parser.rb",
                "lib/calculator.rb",
                "lib/calcex.rb"]#cualquier cosa que nececite la inlcluye aca
  s.license  = 'ARTISTIC'
  s.executables << 'calc'
end
