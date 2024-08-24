# Raspberry Pi Headless Setup Guide

This guide will help you set up your Raspberry Pi without a monitor, keyboard, or mouse by enabling SSH and configuring Wi-Fi (if needed) for headless operation.

## Requirements
- A Raspberry Pi with an SD card slot.
- An SD card (8GB or larger recommended).
- A computer with an SD card reader.
- Raspberry Pi OS image (download from [Raspberry Pi website](https://www.raspberrypi.org/downloads/)).

## 1. Prepare the SD Card
### 1.1. Burn the Raspberry Pi OS Image
1. Download and install the [Raspberry Pi Imager](https://www.raspberrypi.org/software/) or use an alternative tool like **Balena Etcher**.
2. Insert the SD card into your computer.
3. Use the imager to write the Raspberry Pi OS image to the SD card.

### 1.2. Enable SSH
1. Once the image is written, the SD card will be automatically mounted. Navigate to the `boot` partition.
2. In the `boot` partition, create an empty file named `ssh` (no file extension). This will enable SSH on boot.

### 1.3. Set Up Wi-Fi (Optional)
If you want to connect your Raspberry Pi to a Wi-Fi network:
1. In the `boot` partition, create a file named `wpa_supplicant.conf`.
2. Add the following content to the file, replacing `YOUR_SSID` and `YOUR_PASSWORD` with your Wi-Fi network’s SSID and password:

    ```plaintext
    country=KE
    ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
    update_config=1
    network={
        ssid="YOUR_SSID"
        psk="YOUR_PASSWORD"
    }
    ```

    > **Note:** Replace `KE` with your country code if different.

3. Save the file and safely eject the SD card from your computer.

## 2. Boot the Raspberry Pi
1. Insert the prepared SD card into your Raspberry Pi.
2. Power on the Raspberry Pi by connecting it to a power source.

## 3. Find the Raspberry Pi’s IP Address
To SSH into your Raspberry Pi, you need to know its IP address. Here are a few methods to find it:

### Method 1: Router Admin Page
- Log in to your router’s admin page and look for connected devices. The Raspberry Pi should appear as `raspberrypi` or a similar hostname.

### Method 2: Network Scanning Tool
- Use a network scanning tool like **Advanced IP Scanner** (Windows) or **nmap** (Linux/macOS) to scan your local network and find the Raspberry Pi's IP address.

### Method 3: ARP Command (Linux/macOS)
- Open a terminal and run the following command:

    ```bash
    arp -a
    ```

- Look for a device with a name like `raspberrypi` or an unfamiliar IP address that could be the Raspberry Pi.

## 4. SSH into the Raspberry Pi
1. Open a terminal on your computer.
2. Use the following command to SSH into your Raspberry Pi, replacing `raspberrypi.local` with the IP address you found:

    ```bash
    ssh pi@raspberrypi.local
    ```

    or

    ```bash
    ssh pi@<IP_ADDRESS>
    ```

3. When prompted, enter the default password: `raspberry`.

## 5. Complete the Setup
After successfully logging in, you can complete the setup of your Raspberry Pi:

### 5.1. Change the Default Password
For security reasons, change the default password:

```bash
passwd
```
#### HAPPY HACKING!!!
