function demi() {
  local target_dir=$(/home/Demi/Documents/Coding/C/cli-pathing/demi "$@")
  local exit_status=$?
  if [ $exit_status -eq 0 ] && [ -n "$target_dir" ]; then
    if [ -d "$target_dir" ]; then
      cd "$target_dir"
    else
      echo "ERROR: Directory '$target_dir' doesn't exist."
    fi
  fi
}
