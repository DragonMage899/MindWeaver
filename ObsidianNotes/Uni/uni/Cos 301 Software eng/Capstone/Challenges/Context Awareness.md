Keep in mind, focus on OWASP top 10 api for now.

Also note, we should test whether the authorisation field is necessary or perhaps grants unwanted access, also identify type of auth 

## Other Context-Aware Scenarios for OWASP API Top 10 (2023)

Here’s a breakdown tailored to the **OWASP API Top 10 (2023)**, with context-aware flags/examples you should consider for each:

### 1. **Broken Object Level Authorization (BOLA)**

- Test same endpoint with swapped object IDs (userA gets userB’s object)
    
- Detect object/resource ownership (e.g., `/orders/{orderId}` vs `/orders?userId=`)
    
- Watch for non-error (200) responses with different user data
    

### 2. **Broken Authentication**

- Detect missing rate limiting on login/brute force
    
- Detect token reuse (JWT doesn’t expire or is reused across users)
    
- Inspect login endpoints that allow password enumeration by response message differences
    

### 3. **Broken Object Property Level Authorization**

- Can user modify fields they shouldn’t? e.g., `PUT /user/123 {"isAdmin": true}`
    
- Detect hidden/privileged fields in schema (e.g., `role`, `permissions`)
    
- Test submitting restricted fields even if they weren’t returned initially
    

### 4. **Unrestricted Resource Consumption**

- Query parameters like `limit`, `size`, `page`, `depth` — test huge values
    
- Look for download endpoints or nested resource fetching
    
- Look for file upload endpoints without size checks
    

### 5. **Broken Function Level Authorization**

- Can regular users access admin routes?
    
- Test role-restricted paths like `/admin`, `/internal`, `/config`
    
- Check if OpenAPI declares roles (e.g., `securityScopes`) and validate against behavior
    

### 6. **Unrestricted Access to Sensitive Business Flows**

- Check for flows that should require confirmation (e.g., purchase, withdrawal)
    
- Detect if business logic is exposed with no rate limiting (e.g., `/bid`, `/transfer`)
    
- Test if automation is possible where it shouldn’t be (e.g., mass placing orders)
    

### 7. **Server Side Request Forgery (SSRF)**

- Detect if any endpoint accepts a URL or IP (e.g., `/fetch`, `/webhook`, `/callback`)
    
- Test for internal IP hits (`127.0.0.1`, `169.254.169.254`)
    
- Heuristic: look for params like `url`, `target`, `address`, `host`
    

### 8. **Security Misconfiguration**

- Check for missing rate limits
    
- Inspect headers (CORS, Content-Security-Policy)
    
- Check for verbose errors on failure (e.g., stack trace, DB info)
    

### 9. **Improper Inventory Management**

- Look for undocumented routes (crawl vs OpenAPI)
    
- Compare deployed endpoints with spec using a proxy (e.g., mitmproxy)
    
- Flag `/debug`, `/test`, `/v1-old` etc.
    

### 10. **Unsafe Consumption of APIs**

- Check deserialization endpoints (`/parse`, `/convert`, etc.)
    
- Look for endpoints that pass full JSON/XML input to internal services
    
- Test injection payloads if request is proxied or handled by external processors