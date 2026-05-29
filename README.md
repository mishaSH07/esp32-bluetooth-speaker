# Self-Hosted Networking Server (Node.js)

A locally-hosted web server built on a desktop PC, serving a website with text,
images, and video over a local network. Built as a computer engineering project
covering server setup, networking, and web hosting fundamentals.

## What it does
- Serves a static website using Node.js + Express
- Hosts text, image, and video content
- Accessible on the local network (LAN) from other devices

## Tech & concepts
- **Node.js / Express** for the web server
- **Linux Mint** as the host OS
- **Port forwarding** and router configuration for network access
- **BIOS/system optimization** for stable always-on hosting

## Running it
```bash
npm install express
node server.js
```
Then open `http://localhost:6942` in your browser. To reach it from another
device on the same network, find the server's IPv4 address and visit
`http://<server-ip>:6942`.

## Possible improvements
- External access via DuckDNS
- Image compression and caching for faster load times

> Originally built as a Grade 12 computer engineering project.
