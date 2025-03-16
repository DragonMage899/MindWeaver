# Functional Requirements:

##   
  

## R1: Database management

### R1.1: Create and Manage the database

- User should be able to create, edit, and manage the overall database such that the data can be stored and organised.
    
- Users should be able to create a new database with a specified name.
    
- Users should be able to perform CRUD operations on all the data in the database.
    
    - Create
        
    - Read
        
    - Update
        
    - Delete
        
- Before inserting data into the database, users should be able to validate it.
    
- Users should be able to add metadata to the database, this includes:
    
    - Owners
        
    - Collaborators
        
    - Users
        
    - Access editing
        

### R1.2: Data filtering and data searching

- Users should be able to apply filters to database queries.
    
- Users should be able to sort data in a table, either by picking one or more fields.
    
- The filtering and sorting will use JavaScript for implementation on the client side.
    

### R1.3: Importing and Exporting databases

- User should be able to import and export data bases using JSON files.
    
- For exports, the prototype design pattern will be used to clone the database and then from there converted into a JSON file.
    

## R2: Collaboration and Permissions

### R2.1: Adding Collaborators

- Users are able to invite collaborators via their email.
    
- Permission can be specified for each collaborator, this includes:
    
    - Read only
        
    - Write
        
    - Admin
        
- This will form part of the metadata
    

  
  

### R2.2: Managing permissions

- Admins should be able to modify permissions for all users.
    
- Using the memento design pattern, admins should be able to restore previous states of the database.
    
- Public databases will all be read only for security reasons.
    

  
  

## R3: Daemon

### R3.1: External connections:

- The daemon should allow external connections through sockets to enable interaction with the system.
    
- The daemon will listen on a specific port for incoming socket connections.
    
- The daemon should be able to support synchronous communication.
    
- The daemon should also be used to authenticate all external requests.
    

### R3.2: Storing JSON format:

- The daemon should parse and store JSON files so that data is managed in a structured format.
    
- The JSON structure will be predefined.
    

### R3.3: Query Optimisation:

- Queries should be optimised in order for user to retrieve data faster.
    
- Indexing will be used to by the daemon.
    
- The daemon should be able to support filtered responses.
    

### R3.4: Database Management:

- The daemon should support database creation with specified names as well as specified structures.
    
- Users should be able to perform CRUD operations on the database through the daemon.
    
- Concurrent access to the databases should be handled concurrently. *
    

## R4: CLI interface

### R4.1: Connecting to the Daemon

- The daemon shall be connected to via CLI. This will be done using certain command lines.
    
- Only one connection should be permitted at a time. Using the singleton design pattern will help ensure this.
    
- Users should use authentication in order to connect to the daemon, this authentication refers to:
    
    - Username (email)
        
    - Password
        
- The CLI commands should also be able to perform CRUD operations.
    

### R4.2: Batch Operations

- Large databases will sometimes require batch operations and so this should be an option when using CLI.
    
- This means being able to execute multiple CRUD commands in a single batch.
    

##   
  

  
  

## R5: Web UI (API and User Interface)

### R5.1: Responsive Interface

- The user interface should be accessible on all devices. This includes:
    
    - Desktops
        
    - Cell phones
        
    - Tablets
        
- The web UI should contain the following:
    
    - A login page which requests for Username and password along with a register option for first time users.
        
    - A landing page which includes the following:
        
        - A dashboard ( Should this be on a separate page?)
            
        - A side panel with filters and different options.
            
        - A search bar
            
        - All of the public, read-only databases ( or limited to a certain number of them depending on the size)
            
        - Import and export functions
            
    - A data viewing page
        
        - This is where all the CRUD operations and viewing of each database will take place.
            

### R5.2: REST API

- The REST API will integrate the system with the other applications.
    
- The API should support all authentication
    
    - This includes hashing private data for security.
        
- The API will include endpoints which will be used for management, querying, and overall management.
    

  
  

## R6: Security

### R6.1: Encryption

- Data should be encrypted so that everything is secure.
    
- All encryption keys are to be managed securely.
    
- Data is encrypted at rest and in transit.
    
- (ADD MORE AS WE GO)
    

### R6.2: Password Hashing

- Hashing will be used to prevent any unauthorized access, this keeping the databases secure.
    
- User passwords will be hashed using a secure hashing algorithm ( yet to decide )
    
- A trusted library will be used for the password hashing.
    

### R6.2: Logging in and out

- Users will login by using their credentials ( username and password )
    
- Logging out will terminate current session.