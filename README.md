# ft_nm_otool

- to do Makefile with two exec - ft_nm + ft_otool
- TESTS -> https://github.com/mguillau42/unit_test_nm_otool


A Penser :
- fichier object vide dans lib

A faire :
- Verifier les name cpu
- ft_record_fat_arch ! decouper fonction - au niveau de la copie selon arch_64 ou pas et swap ou pas
- Penser a une fonction de deplacement pour chaque structure si struct 64 !
- Jamais oublier le SAFE !!



A faire : lire les bons load commands !!!

* PPC (audiodevice_pcc-32) : empecher la lecture de l'archi ppc --> voir dans ft_fatbinary()
* ATTENTION ==> fonctions non utilisees
* if 32, print 0x 8, if 64, print 0x 16
* look hell/the_revengeance_of_python probleme !! doit sortir !!
* look hell/salam_i_like_cum !!! probleme tri avec chaine null ??

**** VERIFIER LES LEAKS
