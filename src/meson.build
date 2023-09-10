stellaria_sources = [
  'main.c',
  'stellaria-application.c',
  'stellaria-window.c',
]

stellaria_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.2'),
  dependency('webkitgtk-6.0'),
]

stellaria_sources += gnome.compile_resources('stellaria-resources',
  'stellaria.gresource.xml',
  c_name: 'stellaria'
)

executable('stellaria', stellaria_sources,
  dependencies: stellaria_deps,
       install: true,
)
