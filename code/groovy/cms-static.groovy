import flipkart.cms.service.api.CMS_Service
import flipkart.cms.service.api.*
import org.apache.thrift.protocol.TBinaryProtocol
import org.apache.thrift.transport.TSocket

socket = new TSocket("localhost",8000)
protocol = new TBinaryProtocol(socket)
client = new CMS_Service.Client(protocol)

try{
    socket.open()
    println socket.getSocket()
    
    def request 
    def response = client.getProductDetails(new ProductDetailsRequest(["MOBCVUCH7ZYVZVVR"], null, false, false, false))
response.products.each{k, v ->
        def s = v.staticContents
        println s.contentID;
        println "---";
        s.groups.each{println it}
        println "---";
        s.attributeValues.each{it.each{key, value -> println "\t ${key}\t\t${value.valuesList}"}}
        println "---";
        s.transContents.each{
                it.attributeValues.each{println "...";it.each{key, value -> println "\t ${key}\t\t${value.valuesList}"}}
        }
}
} catch(Exception e) {
    println e
} 

