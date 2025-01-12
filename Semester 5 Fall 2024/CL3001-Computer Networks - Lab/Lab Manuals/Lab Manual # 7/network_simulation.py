import ns.core as core
import ns.network as network
import ns.internet as internet
import ns.point_to_point as p2p
import ns.applications as apps
import ns.netanim as netanim

def main():
    # Set up nodes
    nodes = network.NodeContainer()
    nodes.Create(4)

    # Set up internet stack
    stack = internet.InternetStackHelper()
    stack.Install(nodes)

    # Create point-to-point links and set attributes
    p2p1 = p2p.PointToPointHelper()
    p2p1.SetDeviceAttribute("DataRate", core.StringValue("2Mbps"))
    p2p1.SetChannelAttribute("Delay", core.StringValue("10ms"))

    p2p2 = p2p.PointToPointHelper()
    p2p2.SetDeviceAttribute("DataRate", core.StringValue("1.7Mbps"))
    p2p2.SetChannelAttribute("Delay", core.StringValue("20ms"))

    # Install links between nodes
    devices_n0_n2 = p2p1.Install(nodes.Get(0), nodes.Get(2))
    devices_n1_n2 = p2p1.Install(nodes.Get(1), nodes.Get(2))
    devices_n2_n3 = p2p2.Install(nodes.Get(2), nodes.Get(3))

    # Assign IP addresses
    address = internet.Ipv4AddressHelper()
    address.SetBase(core.Ipv4Address("10.1.1.0"), core.Ipv4Mask("255.255.255.0"))
    interfaces_n0_n2 = address.Assign(devices_n0_n2)

    address.SetBase(core.Ipv4Address("10.1.2.0"), core.Ipv4Mask("255.255.255.0"))
    interfaces_n1_n2 = address.Assign(devices_n1_n2)

    address.SetBase(core.Ipv4Address("10.1.3.0"), core.Ipv4Mask("255.255.255.0"))
    interfaces_n2_n3 = address.Assign(devices_n2_n3)

    # Set up TCP connection between n1 and n3
    tcp_sink_helper = apps.PacketSinkHelper("ns3::TcpSocketFactory", network.Address(network.InetSocketAddress(interfaces_n2_n3.GetAddress(1), 8080)))
    tcp_sink_app = tcp_sink_helper.Install(nodes.Get(3))
    tcp_sink_app.Start(core.Seconds(0.0))
    tcp_sink_app.Stop(core.Seconds(5.0))

    tcp_client = apps.BulkSendHelper("ns3::TcpSocketFactory", network.Address(network.InetSocketAddress(interfaces_n2_n3.GetAddress(1), 8080)))
    tcp_client.SetAttribute("MaxBytes", core.UintegerValue(0))  # Unlimited
    tcp_client_app = tcp_client.Install(nodes.Get(1))
    tcp_client_app.Start(core.Seconds(0.5))
    tcp_client_app.Stop(core.Seconds(4.0))

    # Set up UDP connection between n0 and n3
    udp_sink_helper = apps.PacketSinkHelper("ns3::UdpSocketFactory", network.Address(network.InetSocketAddress(interfaces_n2_n3.GetAddress(1), 8081)))
    udp_sink_app = udp_sink_helper.Install(nodes.Get(3))
    udp_sink_app.Start(core.Seconds(0.0))
    udp_sink_app.Stop(core.Seconds(5.0))

    udp_client = apps.OnOffHelper("ns3::UdpSocketFactory", network.Address(network.InetSocketAddress(interfaces_n2_n3.GetAddress(1), 8081)))
    udp_client.SetAttribute("DataRate", core.StringValue("1Mbps"))
    udp_client.SetAttribute("PacketSize", core.UintegerValue(1024))
    udp_client_app = udp_client.Install(nodes.Get(0))
    udp_client_app.Start(core.Seconds(0.1))
    udp_client_app.Stop(core.Seconds(4.5))

    # Set up NetAnim visualization
    anim = netanim.AnimationInterface("network-animation.xml")
    anim.SetConstantPosition(nodes.Get(0), 10, 30)
    anim.SetConstantPosition(nodes.Get(1), 30, 10)
    anim.SetConstantPosition(nodes.Get(2), 30, 30)
    anim.SetConstantPosition(nodes.Get(3), 50, 30)

    # Log network events on the terminal
    def print_tcp_start():
        print("TCP traffic (FTP) started from n1 to n3")

    def print_tcp_stop():
        print("TCP traffic (FTP) stopped from n1 to n3")

    def print_udp_start():
        print("UDP traffic (CBR) started from n0 to n3")

    def print_udp_stop():
        print("UDP traffic (CBR) stopped from n0 to n3")

    # Schedule logging events
    core.Simulator.Schedule(core.Seconds(0.5), print_tcp_start)
    core.Simulator.Schedule(core.Seconds(4.0), print_tcp_stop)
    core.Simulator.Schedule(core.Seconds(0.1), print_udp_start)
    core.Simulator.Schedule(core.Seconds(4.5), print_udp_stop)

    # Run simulation
    core.Simulator.Stop(core.Seconds(5.0))
    core.Simulator.Run()
    core.Simulator.Destroy()

if __name__ == "__main__":
    main()
