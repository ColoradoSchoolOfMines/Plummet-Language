# Syntax Prototypes

## OOP-like Syntax

### Style 1

```
import "stdlib/system"

public system::main(args: string[]) -> void {
	
}
```

### Style 2

```
class FileName:
    public static void main(string[] args):
        doSomething();
```

## Multi-Paradigm Syntax

### Style 1

```
import "std/system";

func main() -> <void> {
    args: <string[] | null> = system.args;

    if (args == null) {
        return;
    }

    for (str: <string> ~ args) {
        system.print(str);
    }
}
```
