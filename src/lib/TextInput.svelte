<script lang="ts">
    import { onMount } from 'svelte';

    export let value: string = '';
    export let placeholder: string = 'Enter text...';
    export let type: string = 'default';
    export let width: number = 15;
    export let inputRef: HTMLInputElement | null = null;
    export let align: string = 'left';
    export let uppercase: boolean = false;
    export let margin: number = 1;

    switch(type) {
        case 'single':
            placeholder = '';
            width = 1.6;
            align = 'center';
            break;
    }

    onMount(() => {
        if(!inputRef) return;
        inputRef.addEventListener('keydown', (e) => {
            if(!inputRef) return;
            if(e.key === 'Escape')
                inputRef.blur();
        });

        inputRef.addEventListener('input', () => {
            if(uppercase)
                value = value.toUpperCase();

            switch(type) {
                case 'single':
                    if(value.length > 1)
                        value = value[value.length-1];
                    break;
            }
        });
    });
</script>

<input
    bind:this={inputRef}
    bind:value
    placeholder={placeholder}
    style={`
        width: ${width}rem;    
        text-align: ${align};
        margin: ${margin}rem;
    `}
/>

<style>
    input {
        height: 3rem;
        padding: 1rem 1.5rem;
        border: 2px solid #444;
        background: transparent;
        color: var(--light);
        font-size: 20pt;
        outline: none;
        transition: all 0.2s;
    }

    input:focus {
        border-color: var(--light);
        transform: scale(1);
    }

    input:hover:not(:focus-visible) {
        transform: scale(1.05);
    }
</style>
