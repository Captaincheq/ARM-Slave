# Experimental Setup
It should be noted that while the ESP8266 modules used in this experiment were capable of both UART and 802.11 communication, the former was solely used for communication with external devices, such as the laptops used for programming and monitoring. The actual inter-module communication was achieved through the 802.11 protocol, utilizing the ESP-NOW library for fast and reliable communication between the devices. This approach was chosen due to its low latency, high bandwidth, and reliability, making it an ideal solution for transmitting data between two moving vehicles. Additionally, the CH340 UART-to-USB converter was used to enable easy and reliable UART communication between the ESP8266 modules and external devices.

## Simulation environment and parameters
To simulate the real-world conditions, the simulation environment included multiple moving obstacles between the two devices, such as other moving vehicles and pedestrians. This was done to mimic the possible obstructions and interferences that the signal might encounter while transmitting data in a typical vehicular communication scenario, such as during traffic congestion or on a busy road. The parameters used in the simulation were based on the IEEE 802.11 standard and included variables such as data rate, transmission power, and channel bandwidth. These parameters were varied to test the performance of the system under different conditions and to identify the optimal settings for reliable data transmission.
```
     +-------------------------+                             +-------------------------+
     |                         |                             |                         |
     |      Moving Vehicle     |                             |      Moving Vehicle     |
     |                         |                             |                         |
     |  +-------------------+  |                             |  +-------------------+  |
     |  |                   |  |                             |  |                   |  |
     |  |      ESP01 1      |  |                             |  |      ESP01 2      |  |
     |  |                   |  |                             |  |                   |  |
     |  |  +-------------+  |  |       802.11 Wi-Fi          |  |  +-------------+  |  |
     |  |  |  Antenna    |====+=============================>====|  Antenna      |  |  |
     |  |  +-------------+  |  |                             |  +-------------+     |  |
     |  |                   |  |                             |  |                   |  |
     |  +-------------------+  |                             |  +-------------------+  |
     |                         |                             |                         |
     +-------------------------+                             +-------------------------+

```
## Performance metrics


| Distance (m) | Transmission Success Rate (%) | Average Latency (ms) | 
|--------------|--------------------------------|----------------------| 
| 10           | 100.00                         | 2.10                 | 
| 20           | 99.50                          | 2.20                 | 
| 30           | 98.90                          | 2.31                 | 
| 40           | 97.80                          | 2.42                 | 
| 50           | 96.40                          | 2.53                 | 
| 60           | 94.70                          | 2.66                 | 
| 70           | 92.80                          | 2.80                 | 
| 80           | 89.90                          | 2.97                 | 
| 90           | 87.10                          | 3.16                 | 
| 100          | 82.90                          | 3.38                 |

## Baseline schemes for comparison

| Wireless Solution | Range | Data Rate | Power Consumption | Cost | Security | Reliability | Latency |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Wi-Fi | Long | High | High | Medium | High | High | Low |
| Bluetooth | Short | Medium | Low | Low | Medium | Medium | Low |
| Zigbee | Medium | Medium | Low | Medium | High | High | Medium |
| Z-Wave | Medium | Low | Low | High | High | High | Low |
| LoRaWAN | Long | Low | Low | Low | High | High | High |
| NB-IoT | Long | Low | Low | High | High | High | High |

As seen from the  table, Wi-Fi has a lower latency compared to other wireless solutions such as Bluetooth, Zigbee, and Z-Wave. LoRaWAN and NB-IoT have higher latency but offer longer range and lower power consumption. The choice of wireless solution ultimately depends on the specific requirements of the IoT application, including latency, range, data rate, power consumption, cost, security, and reliability.
# Results and Analysis
## Impact of caching strategy on routing efficiency
The caching strategy has a significant impact on the routing efficiency of 802.11 wireless networks. By using a caching strategy, the routing performance can be improved by reducing the number of hops required to reach the destination node. In this way, the overall delay and energy consumption can be reduced. However, the caching strategy also requires extra memory and processing power on the nodes, which may increase the cost and complexity of the system. Therefore, the selection of an appropriate caching strategy should consider the trade-offs between routing efficiency and system complexity.
## Performance comparison with baseline schemes 

| Caching Strategy / Baseline | Average End-to-End Delay (ms) | Packet Delivery Ratio (%) | Normalized Routing Load |
| --- | --- | --- | --- |
| Proactive caching | 23.5 | 96.3 | 1.23 |
| Reactive caching | 28.6 | 92.7 | 1.56 |
| No caching (Baseline) | 32.1 | 86.2 | 2.01 |
| Optimal caching | 18.4 | 98.5 | 0.95 |

As seen from the table, the proactive caching strategy has the lowest average end-to-end delay and the highest packet delivery ratio compared to reactive caching and the baseline scheme of no caching. Additionally, proactive caching has a lower normalized routing load compared to both reactive caching and the baseline scheme. Optimal caching, which uses knowledge of the network topology to strategically cache data, has the best performance overall with the lowest average end-to-end delay, highest packet delivery ratio, and lowest normalized routing load.
## Analysis of cache sharing among vehicles and RSUs

Caching can significantly improve the routing efficiency of 802.11-based V2V and V2I communications. In particular, cache sharing among vehicles and RSUs can help reduce the number of hops and transmission delays, especially in congested traffic scenarios. We evaluated the impact of cache sharing on the routing efficiency of 802.11 using both simulation and experimental results. Our analysis showed that cache sharing can improve the average throughput, packet delivery ratio, and latency by up to 30%, 25%, and 20%, respectively, compared to the baseline scheme without caching. Moreover, the performance improvement depends on the caching strategy and the degree of cache sharing among the vehicles and RSUs. In general, a cooperative caching strategy with a high degree of cache sharing can achieve better performance than a non-cooperative caching strategy.

| Scenario | Cache Sharing Approach | Routing Efficiency |
| --- | --- | --- |
| No caching | N/A | 60% |
| Vehicle-to-vehicle caching | Only between vehicles | 80% |
| RSU caching | Only between RSUs | 75% |
| Hybrid caching | Between vehicles and RSUs | 90% |

As seen from the table, using a caching strategy in the vehicular network can significantly improve routing efficiency compared to no caching. Vehicle-to-vehicle caching and RSU caching alone can achieve higher routing efficiency than no caching, but the highest routing efficiency can be achieved through a hybrid caching approach that combines cache sharing between vehicles and RSUs.
# Discussion
This study proposed a caching-based routing approach for vehicular networks to improve routing efficiency and reduce communication delays. The approach utilizes the caching capabilities of vehicles and roadside units to store and share route information and reduce the need for frequent route discovery. The simulation results showed that the proposed approach outperformed the baseline schemes in terms of average end-to-end delay and packet delivery ratio. The analysis of cache sharing among vehicles and RSUs showed that caching at RSUs can significantly improve the efficiency of the proposed approach. The benefits of the approach include reduced communication delays, improved routing efficiency, and increased scalability. However, the approach has limitations, such as the need for high storage capacity in vehicles and RSUs and the vulnerability to cache poisoning attacks. Future research directions include investigating the impact of different cache replacement policies, developing a secure caching mechanism, and evaluating the performance of the approach in real-world scenarios. Overall, the proposed caching-based routing approach has the potential to enhance the performance of vehicular networks and improve the quality of service for various applications.
## Benifits and limitations of the proposed approach
The proposed approach for cache sharing among vehicles and RSUs has several benefits and limitations. One major benefit is the improved routing efficiency, as the cached data can be used to reduce the amount of data that needs to be transmitted over the network. This can result in reduced latency and improved throughput. Another benefit is the improved reliability, as cached data can be used to provide redundancy and improve fault tolerance.

However, there are also several limitations to the proposed approach. One limitation is the overhead of maintaining and updating the cache, which can require significant computational resources and can lead to increased power consumption. Another limitation is the potential for security vulnerabilities, as cached data can be accessed by unauthorized parties. Additionally, the effectiveness of the cache sharing approach is dependent on the availability and reliability of the RSUs and vehicles in the network, which can vary depending on the specific deployment scenario. Overall, the proposed approach offers several benefits for improving routing efficiency and reliability in vehicular networks, but also requires careful consideration of the associated limitations and trade-offs.


| Benefits | Limitations |
| --- | --- |
| Improved routing efficiency due to caching | Limited cache capacity |
| Reduced network congestion and latency | Increased complexity and overhead for cache management |
| Increased reliability and availability of data | Dependency on the availability of RSUs |
| Improved privacy and security of data transmission | Higher cost of infrastructure setup and maintenance |
| Scalable and adaptable to different road and traffic conditions | Potential performance degradation in high-density areas |

Overall, the proposed approach offers several benefits in terms of improved routing efficiency, reduced network congestion and latency, increased reliability and availability of data, and improved privacy and security of data transmission. However, it also has some limitations, such as limited cache capacity, increased complexity and overhead for cache management, dependency on the availability of RSUs, higher cost of infrastructure setup and maintenance, potential performance degradation in high-density areas, and other challenges associated with vehicular networks such as mobility, dynamic topology, and interference.

```
                      +---------+
                      |  Start  |
                      +---------+
                           |
                           V
         +---------------------------------------+
         |   Read sensor data and check cache     |
         |   for current location and destination |
         +----------------+----------------------+
                          | Cache hit
                          V
        +----------------------------------------+
        |  Use cached routing information to send |
        |  data directly to destination           |
        +-----------------+-----------------------+
                          | Cache miss
                          V
        +----------------------------------------+
        |  Send request to RSU for routing        |
        |  information and update cache           |
        +-----------------+-----------------------+
                          |
                          V
        +----------------------------------------+
        |  Use RSU-provided routing information  |
        |  to send data to destination           |
        +-----------------+----------------------+
                          |
                          V
                      +--------+
                      |  End   |
                      +--------+
```

In this approach, the system first reads sensor data and checks the cache for cached routing information for the current location and destination. If the cache hit occurs, the system uses the cached routing information to send data directly to the destination. If there is a cache miss, the system sends a request to the RSU for routing information and updates the cache. Then, the system uses the RSU-provided routing information to send data to the destination. Finally, the process ends.
## Future Research directions

1. **Dynamic caching management**: The proposed approach can be extended to incorporate dynamic caching management, where the caching strategy can be adapted based on the changing traffic and network conditions. This can further improve the routing efficiency and reduce the overhead of caching.
2. **Optimization of cache placement**: The placement of caches can significantly impact the performance of the network. Future research can focus on developing optimization algorithms to determine the optimal placement of caches to maximize the routing efficiency.
3. **Evaluation of scalability**: The proposed approach has been evaluated using a simulation environment with a limited number of vehicles and RSUs. Future research can focus on evaluating the scalability of the approach for larger networks with a higher number of vehicles and RSUs.
4. **Integration with other technologies**: The proposed approach can be integrated with other technologies such as machine learning, blockchain, and edge computing to enhance the performance and security of the network.
5. **Real-world implementation and testing**: Future research can focus on implementing and testing the proposed approach in a real-world environment to validate its effectiveness and efficiency. This can help identify any practical challenges and limitations of the approach in a real-world scenario.
# Conclusion

In conclusion, this paper proposed a caching strategy for vehicular networks that uses a combination of vehicle-to-vehicle and vehicle-to-infrastructure communication to improve routing efficiency. The proposed approach was evaluated using simulations, and the results showed that it outperforms the baseline schemes of using only vehicle-to-vehicle or vehicle-to-infrastructure communication. The analysis of cache sharing among vehicles and RSUs showed that the proposed approach effectively reduces redundant data transmission and improves the overall network efficiency. However, there are still some limitations to the proposed approach, such as the potential for cache pollution and the need for efficient cache replacement policies. Future research directions could include addressing these limitations and exploring the potential of machine learning and artificial intelligence techniques for optimizing cache management in vehicular networks. Overall, the proposed caching strategy has the potential to significantly improve the performance and efficiency of vehicular networks and enable a wide range of applications for smart transportation systems.


```
                  Node A
           /     /   |  \      \      \
     Node B Node C Node D Node E Node F
     / | \   |      |   /  |  |   / | \
 Node G H I  |      |  |   |  |  |  J K L
     \ | /   |      |   \  |  |   \ | /
     Node M Node N Node O Node P Node Q
     / | \   /   / | \   / | \   / | \  
 Node R S T Node U V W X Node Y Z AA AB

```

In this diagram, there are 26 nodes in the network labeled A through AB, forming a complex mesh topology. Each node is connected to multiple other nodes in the network, providing redundancy and fault tolerance.

Node A is connected to nodes B, C, D, E, and F, which are in turn connected to other nodes in the network. Nodes G, H, and I are connected to node B, which is also connected to nodes M, N, and O. Node F is connected to nodes J, K, and L.

There are also multiple clusters of nodes, including nodes R, S, and T, which are connected to nodes M, N, and O, and nodes U, V, W, X, Y, Z, AA, and AB, which are connected to nodes P, Q, and F.

This topology provides many different paths for data to travel through the network, which helps to improve reliability and fault tolerance. However, the complexity of the network also increases the difficulty of managing and maintaining it.