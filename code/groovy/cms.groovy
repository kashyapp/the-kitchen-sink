import flipkart.cms.service.api.CMS_Service
import flipkart.cms.service.api.*
import org.apache.thrift.protocol.TBinaryProtocol
import org.apache.thrift.transport.TSocket

socket = new TSocket("cms-svc.nm.flipkart.com",26201)
protocol = new TBinaryProtocol(socket)
client = new CMS_Service.Client(protocol)

try{
    socket.open()
    println socket.getSocket()
    
    def request 
    //request = new ServiceCentersRequest('MOBCPD44TJGVNADN',[postal_code:'520002'],0,100)

    println socket.getSocket()
    //def response = client.getServiceCenters(request)
    
    //println response
    client.metaClass.methods*.name.sort().unique().each{println it}

    println client.getSupplierInfo(new SourceInfoRequest(['mumElsevierPmum','kolProjoptiPkol','WisemenPdel','blrElsevierPblr']))

} finally {
    socket.close()
    println socket.getSocket()
}

