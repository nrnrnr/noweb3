dofile('totex.nws')
P = MPipe
f = P.source(Stages.markup, {'totex.nw'})
b = P.sink(Stages.totex, {})
p = P.connect(f, b)
P.run(p)

