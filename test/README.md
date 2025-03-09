```mermaid
flowchart TD;
    A[Start] --> B{Is Format String NULL?};
    B -- Yes --> C[Print "Error: formatString is NULL"];
    B -- No --> D[Start Loop Over Format String];
    D --> E{Is Character '%'?};
    E -- No --> F[Print Character];
    E -- Yes --> G{Is Next Character Format Specifier?};
    G -- Yes --> H[Find Correct Format Function];
    G -- No --> I[Print '%' and Next Character];
    H --> J[Call Appropriate Format Function];
    J --> D;
    D --> K[Continue Until End of Format String];
    K --> L[Return Count of Printed Characters];
    L --> M[End];
```
