################################################################
#
# kppp ruleset for Italy
#
# by Luca Boni (me9139@mclink.it)
#
# Infostrada_Libero1055_SpZero.rst
#
# NOTA:
# Questa tariffa e' identica a Infostrada_Libero1055_Base.
# E' stata inserita per maggior chiarezza, dato che l'operatore
# la applica anche per i contratti SpazioZero.
#
# INTERNET
# Collegamenti Internet con Libero 1055.
#
# Ultimo aggiornamento: 7 Marzo 2002.
#
################################################################
##							      ##
## Addebito alla risposta di 0,0775 EUR.  	      	      ##
## 	     						      ##
## Tutti i prezzi si intendono in EUR/min IVA COMPRESA.       ##
##							      ##
##							      ##
## 		Tariffa RIDOTTA: 0,0190	EUR		      ##
## 		Tariffa INTERA : 0,0350	EUR		      ##
## 		Tariffa MINIMA : 0,0095	EUR		      ##
##		   					      ##
##		    | Ridotta   dalle 18:30 alle 08:00	      ##
## Giorni FERIALI : |					      ##
##		    | Intera    dalle 08:00 alle 18:30	      ##
##							      ##
##			          			      ##
## Giorni FESTIVI : | Minima 	dalle 00:00 alle 24:00        ##
##	 e SABATO : | 	      	      			      ##
##							      ##
################################################################


# Nome del ruleset
name=Infostrada_Libero1055_SpZero

# Impostazioni della valuta
currency_symbol=EUR
currency_position=right
currency_digits=2

# Addebito alla risposta
per_connection=0.0775

# Giorni feriali a tariffa ridotta
default=(0.0190, 60)

# Giorni feriali a tariffa intera
on (monday..friday) between (8:00..18:30) use (0.0350, 60)

# Giorni festivi e sabato: tariffa minima
on (saturday) between () use (0.0095, 60)
on (sunday) between () use (0.0095, 60)
on (01/01) between () use (0.0095, 60)
on (01/06) between () use (0.0095, 60)
on (04/25) between () use (0.0095, 60)
on (05/01) between () use (0.0095, 60)
on (08/15) between () use (0.0095, 60)
on (11/01) between () use (0.0095, 60)
on (12/08) between () use (0.0095, 60)
on (12/25) between () use (0.0095, 60)
on (12/26) between () use (0.0095, 60)
on (easter) between () use (0.0095, 60)
on (easter + 1) between () use (0.0095, 60)

# Fine
