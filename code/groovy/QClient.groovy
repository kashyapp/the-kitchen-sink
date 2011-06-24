import flipkart.platform.queueinterface.*
import org.apache.thrift.*
import org.apache.thrift.protocol.*
import org.apache.thrift.transport.*

public class QClient {
    def run() {
        def socket = new TSocket('localhost', 8888)
        socket.open()
        println socket.getSocket()
        def protocol = new TBinaryProtocol(socket)
        def client = new QueueService.Client(protocol)

        def items = client.dequeueItems('CMS_UPDATE_STOCK_BOOKS_NM', 1)
        items.each {
            println it
        }
    }

    public static void main(args) {
        new QClient().run()
    }
}
