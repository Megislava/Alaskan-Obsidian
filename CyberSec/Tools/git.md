- version control
	- VCS = Version Control System


### Data model
- history of collection of files and folders in a snapshot
	- snapshot = top-level tree
	- folders 
		- = tree
		- maps names of blobs and trees
	- files 
		- = blob
		- just bunch of bytes
- history is directed in irected acyclic graph (DAG)
	- each snapshot refers to a set of "parents" that that snapshot preceded
		- last snapshot/commit (most right) refers to both parents aka on master and on it's "home" branch
		```
		o <-- o <-- o <-- o <---- o
					^            /
					 \          v
					  --- o <-- o
		```
	- snapshots = commits
- data model in pseudocode:
	```
	// a file is a bunch of bytes
	type blob = array<byte>
	
	// a directory contains named files and directories
	type tree = map<string, tree | blob>
	
	// a commit has parents, metadata, and the top-level tree
	type commit = struct {
	    parents: array<commit>
	    author: string
	    message: string
	    snapshot: tree
	}
	```
- objects
	- blob, tree, commit
	- content-addressed by SHA-1 hash
	- immutable (unchanchable in history - can be changed only later ~ overwritten)
- references
	- human readable names for SHA-1 hashes
	- mutable
- HEAD
	- where we currently are
- repositories
	- objects and references

### Staging area
- changes in folder and files (trees and objects) that git follows/sees


### Git CLI
- all prefixed with `git`

- `help`
- `init` - initiates a new repo
- `status` - what is going on
- `add <filename>` - adds files to staging area
	- `-p` - interactive staging
- `commit` - creates a new commit
	- `--amend` - edit a commits content/message
- `log` - flattened history
	- `log --all --graph --decorate` - visulizes the history of DAG
- `diff <filename>` - changes made relative to staging area
	- `diff <revision> <filename>` - difference in a file between snapshots

- `checkout <revision>` - updates HEAD and current branch
- `branch` - shows branches
	- `branch <name>` - creates a branch
		- `branch --set-upstream-to=<remote>/<rmemote branch>` - set up "talking" path between remote and local branch
- `checkout -b <name>` - creates a branch a switches to it
	- → same as `git branch <name>; git checkout <name>`
	- `checkout -- <file>` - discard changes
- `merge <revision>` - merges into current branch
	- `merge mergetool` - use a tool to help resolve merge conflicts
- `rebase` - rebase set of patches **onto** a new base
	- `-i` - interactive rebasing

- `remote` - list remotes
	- `remote add <name> <url>` - add a remote
	- kept in git.config
- `push <remote> <local branch>:<remote branch>` - send changes to remote
- `fetch` - retrieve objects/references from a remote
- `pull` - same as `git fetch; git merge`
- `clone` - download repository from remote

- `reset HEAD <file>` - unstage a file
- `blame` - who edited which line
- `stash` - temporarily remove modification to working directory