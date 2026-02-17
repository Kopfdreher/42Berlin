# NetPractice

*This project has been created as part of the 42 curriculum by [sgavrilo].*

## Description

**NetPractice** is a 42 school project designed to solidify your understanding of networking, specifically focusing on **IPv4 addressing** and **subnetting**.

The project consists of a series of networking puzzles presented through a web interface. Each level requires you to configure IP addresses, subnet masks, and routing tables to ensure that all devices in a given network can communicate correctly.

### Key Concepts Covered:

* **IP Addressing:** Understanding how to assign valid addresses to hosts and routers.
* **Subnet Masks:** Mastering CIDR notation (e.g., `/24`) and its decimal equivalents (e.g., `255.255.255.0`).
* **Routing:** Configuring gateways and routing tables to facilitate data transfer between different subnets.
* **Network Limits:** Identifying the network address, broadcast address, and the range of usable host IPs.

---

## Instructions

Since NetPractice is a web-based training tool provided by 42, there is no source code to compile. However, you can run the practice environment as follows:

1. **Access:** Open the `index.html` file (provided in the project repository) in any modern web browser.
2. **Configuration:** * Look at the network diagram provided in each level.
* Fill in the missing IP addresses, masks, or next-hop routes.


3. **Validation:** Click the **"Check"** button.
* **Green:** The configuration is correct, and all nodes can ping each other.
* **Red:** There is a configuration error (e.g., overlapping subnets or unreachable hosts).



---

## Resources

### References

* **NetworkChuck - "You suck at Subnetting":** This YouTube series was the primary catalyst for understanding binary math and the "magic number" method used to calculate subnets quickly.
* **42 Peer Discussions:** Insights gained from fellow students regarding common pitfalls, such as the difference between a private and public IP range.

### Use of AI

AI was utilized in the following capacity for this project:

* **Conceptual Clarification:** Used to explain the specific logic behind routing tables and how a router decides where to send a packet when multiple routes overlap.

---

## Technical Choices

* **The "Magic Number" Method:** I opted to use the magic number technique learned from NetworkChuck to solve levels quickly without converting every IP to binary.
