# Nm-Otool

# Sources
http://opensource.apple.com/source/cctools/cctools-698.1/include/mach-o/
http://opensource.apple.com/source/cctools/cctools-698.1/include/mach-o/loader.h
http://opensource.apple.com/source/cctools/cctools-698.1/include/mach-o/fat.h
http://opensource.apple.com/source/cctools/cctools-698.1/include/mach-o/nlist.h
http://opensource.apple.com/source/cctools/cctools-698.1/include/mach-o/ranlib.h
http://lowlevelbits.org/parsing-mach-o-files/

# Other
Ajout des fonctions suivantes dans la libft:

_ft_options -> Puissant parser d'options sur un program, sans malloc utilise un singleton pour stocker les options.
_ft_error -> retourne toujours 0 et affiche l'erreur et le message d'erreur sur la sortie d'erreur.

# Bug
segfault sur un repertoire. #fixed
