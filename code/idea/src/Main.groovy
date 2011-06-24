
/**
 * Created by IntelliJ IDEA.
 * User: kashyapp
 * Date: 21/2/11
 * Time: 12:53 AM
 * To change this template use File | Settings | File Templates.
 */

import flipkart.platform.queueinterface.QueueService
import org.apache.thrift.transport.TSocket
import org.apache.thrift.protocol.TBinaryProtocol
import org.json.simple.JSONObject
import org.json.simple.JSONValue


socket = new TSocket("pf-mq1.nm.flipkart.com", 28002)
protocol = new TBinaryProtocol(socket)
client = new QueueService.Client(protocol)

socket.open()

items = client.dequeueItems("CMS_UPDATE_STOCK_BOOK_NM", 10)

data = items.each {item ->
    data = item.getData()
    json = (JSONObject)JSONValue.parse(data)
    json.put("itemId", item.getItemId())
    item.beta = json
}

println items

grouped = data.groupBy {item ->
    item.beta["sourceID"]
}

println grouped