################################################################
#
# This is an accounting set for Telkom South Africa
# Please note that the costs used are those corresponding to
# the 2003/2004 directory and are based on local phone calls
# being made. All calls are charged per second.
# Callmore time is implemented in this rule set.
# Call rates may change and I hold no responsibility for improper
# use of this rule set.
#
# This rule set was last updated: 29 September 2003
# by Males Tomlinson <vorsicht@webmail.co.za>
# Distance:________________Local Call (0-50km)
# Charges: Standard time:__0,37c per/min
#          Callmore time:__0,14c per/min
# Minimum call charges:____55c
#
#
#  - If unsure, contact your Internet service provider to
#    determain your call distance and Telkom SA for up to date
#    charge rates.
#
################################################################

################################################################
#
# NAME OF THE RULESET. This is NEEDED for accounting purposes.
#
################################################################
name=South_African_Local_Call_0-50km

################################################################
# currency settings
################################################################

# Currency symbol R ('Rand') eg, R 1.20 would imply 1 Rand and 20 cents
currency_symbol=R
currency_position=left
currency_digits=2

################################################################
# connection settings
################################################################

# NOTE: rules are applied from top to bottom - the
#       LAST matching rule is the one used for the
#       cost computations.

# This is charged whenever you connect. If you don't have to
# pay per-connection, use "0" here or comment it out.
per_connection=0

# minimum costs per per connection. If the costs of a phone
# call are less than this value, this value is used instead
minimum_costs=0.55

#flat_init_costs=(0)
#default=(0)

#
# more complicated rules:
#

# This is used for the so called 'CallMore Time' schedule that was
# introduced by Telkom.(R0,0024 every second)
#
on (saturday..sunday) between (0:00..23:59) use (0.0024,1)
on (monday..friday) between (0:00..06:59) use (0.0024,1)
on (monday..friday) between (19:00..23:59) use (0.0024,1)

# This is used for the so called 'Normal Time' schedule
# (R0,0062 every second)
on (monday..friday) between (07:00..18:59) use (0.0062,1)
