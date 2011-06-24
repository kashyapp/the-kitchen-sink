name = 'Kashyap Paidimarri'
age = 26 # not a lie
height = 71 # inches
weight = 63 # kgs
eyes = 'Black'
teeth = 'White'
hair = 'Black'

inch_to_cm = 2.54

print "Let's talk about %s." % name
print "He's %d inches tall." % height
print "He's %d centimeters tall." % (height * inch_to_cm)
print "He's %d kilograms heavy." % weight
print "Actually that's not too heavy."
print "He's got %s eyes and %s hair." % (eyes, hair)
print "His teeth are usually %s depending on the coffee." % teeth
print "Try out %%r %05d" % 123

# this is tricky, try get it exactly right
print "If i add %d, %d, and %d I get %d." % (
        age, height, weight, age + height + weight)

