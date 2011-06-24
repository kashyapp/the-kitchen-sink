import flipkart.platform.queueinterface.*
import org.apache.thrift.*
import org.apache.thrift.server.TSimpleServer
import org.apache.thrift.protocol.*
import org.apache.thrift.transport.*

public class QServer extends TSimpleServer {
    public QServer() {
        super (
                new QueueService.Processor(new QServiceImpl()), 
                new TServerSocket(8888, 5000)
              )
    }

    public static void main(args) {
        println "starting server"
        new QServer().serve()
    }
}

class QServiceImpl implements QueueService.Iface {
    private static queue =  [
            new Item('id1', '{"productID":"9780061124235", "sourceID":"BangaloreWarehouse", "sourceType":"WAREHOUSE", "quantityChanged":3}', 1947, null, 'CMS_UPDATE_STOCK_BOOKS_NM'),
            new Item('id2', '{"productID":"9780061124259", "sourceID":"BangaloreWarehouse", "sourceType":"WAREHOUSE", "quantityChanged":3}', 1947, null, 'CMS_UPDATE_STOCK_BOOKS_NM'),
            new Item('id3', '{"productID":"978006112425X", "sourceID":"BangaloreWarehouse", "sourceType":"WAREHOUSE", "quantityChanged":3}', 1947, null, 'CMS_UPDATE_STOCK_BOOKS_NM'),
        ]
    private static queue_bak = []

    public void enqueueItem(String queuename, String data) throws QueueServiceException, TException {
        throw new QueueServiceException("not implemented")
    }

    public List<Item> dequeueItems(String queuename, int numOfItems) throws QueueServiceException, TException {
        if (queue) {
            def item = queue.pop()
            queue_bak.push(item)
            return [item]
        } else {
            println "queue empty, refreshing"
            queue = queue_bak
            queue_bak = []
            return []
        }
    }

    public List<Item> readItems(String queueName, int numOfItems) throws QueueServiceException, TException {
        println "readItems " + queueName + " " + numOfItems
        throw new QueueServiceException("not implemented")
    }

    public void deleteItems(String queuename, List<String> itemIdList) throws QueueServiceException, TException {
        throw new QueueServiceException("not implemented")
    }

    public QueueInfo getQueueInfo(String queuename) throws QueueServiceException, TException { 
        throw new QueueServiceException("not implemented")
    }

    public void sideLineItem(Item item, String exception1) throws QueueServiceException, TException {
        println $item + " " + $exception1
    }
}


