import org.apache.thrift.*
import org.apache.thrift.server.*
import org.apache.thrift.protocol.*
import org.apache.thrift.transport.*

def impl = [
    registerClient : { email ->
        println "registering: ${email}"
        return true
    },

    startTurn : {
        return [Color.RED, Color.YELLOW]
    },

    chooseColor : { color ->
        println "got color: ${color}"
        return true
    },

    endTurn : {
        return true
    },

    winGame : {
        return "rumpelstiltskin"
    },
]

def processor = new SimonSays.Processor(impl as SimonSays.Iface)
def socket = new TServerSocket(9030)
def server = new TSimpleServer(processor, socket)

println "starting server"
server.serve()
