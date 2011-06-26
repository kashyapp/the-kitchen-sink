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
    def response = client.getProductDetails(new ProductDetailsRequest(["MOBCVUCH7ZYVZVVR","MOBCTXF8SJSPWW7F","MOBCZQ5DJ4Y7RJAP","CAMCUTS22P44GHPP","ACCCX3SGDZFGCGHX"], null, false, false, false))
response.products.each{k, v ->
        println "******************\nproduct_id : ${k}"
        println "has_image : " + v.attributeValues['has_image']?.valuesList
        println "primary_content_id : " + v.attributeValues['primary_content_id']?.valuesList
        v.staticContents.each {s ->
            println "\t >>>${s.contentID}<<<"
            s.groups.each{println "\t\t" + it}
            s.attributeValues.each{ key, value -> println "\t\t ${key}\t\t\t${value.valuesList}" }
            foo = {println "\t\t===";
                it.attributeValues.each{key, value -> println "\t\t ${key}\t\t\t${value.valuesList}"}
            }
            // s.transContents.each(foo)
            foo(s.transContents.last())
        }
}
} catch(Exception e) {
    println e
} 

