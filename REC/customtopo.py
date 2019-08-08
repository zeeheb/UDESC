from mininet.topo import Topo

class MyTopo ( Topo ) :
    "Simple topology example"

    def __init__(self):

        Topo.__init__(self)

# h1 --- s3 --- s4 --- h2

        for h in range(4):
            host = self.addHost('h%s' % (h + 1))
            self.addLink(host, switch, bw=60, delay='30ms', loss=2, max_queue_size=1000, use_htb=True)



topos = { 'mytopo': ( lambda: MyTopo() ) }
