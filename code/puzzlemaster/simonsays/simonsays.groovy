import org.apache.thrift.*
import org.apache.thrift.protocol.*
import org.apache.thrift.transport.*

def socket = new TSocket('localhost', 9030)
def protocol = new TBinaryProtocol(socket)
def client = new SimonSays.Client(protocol)

try {
    socket.open()
    println socket.getSocket()
} catch (e) {
    e.printStackTrace()
}

def registered = client.registerClient('kashyapp@gmail.com')

def completed = false
while (!completed) {
    def colors = client.startTurn()
    println "colors ${colors}"
    colors.each { color ->
        def chosen = client.chooseColor(color)
        println "${color} ${chosen}"
    }
    completed = client.endTurn()
    println "completed: ${completed}"
}

def token = client.winGame()
println token
